/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <device.h>
#include "Utils.h"
#include <stdio.h>
#include "math.h"
#include "slip.h"
#include "buffer.h"

#define NUM_AVERAGE   4
#define NUM_CHANNELS  7

#define TRUE 1 
#define FALSE 0

#define HIGH 1
#define LOW 0

#define RBTQ1 1
#define RBTQ2 2

#define RCERROR 50
#define SATURATION 1000 //use 500 for half speed

#define TIMERPERIOD 4294967296

#define EXTENDARM 1
#define RETRACTARM 2

//slip receive buffer
static char rxData[64];
static cBuffer rxDataBuffer = MAKE_BUFFER(rxData);

//Describe an RC channel
typedef struct 
{
	volatile uint32 start; //rising edge timer capture
	volatile uint32 end; //falling edge timer capture
	uint8 count; //used to keep track of how many differences have been calculated so far.
	
	uint32 difference[NUM_AVERAGE]; //each difference represents the pulse width in microseconds
	volatile uint32 average;
} Channel;

//Describe a motor
typedef struct
{
	uint8 roboteq; //which roboteq controls this motor (1 or 2)
	uint8 port; //which port on the roboteq it is (1 or 2)
	int power; //the current power being sent to this motor, [-1000, 1000]
} Motor;

typedef struct
{
	int x, y, r;
	//uint16 magnitude;
	//int angle;
} Vector;

//---Function Prototypes

// extend arm for grabbing the flag off of the purple boat thingy
void extendArm();
void retractArm();
void stopArm();


//Communicate to the uart the values of the rc channels and print them nicely
void DisplayChannelValues();

//Display the vector properties to the uart
void DisplayVector(const Vector vec);

//calculate the difference between the first and the second timestamps
uint32 getDifference(uint32 start, uint32 end) reentrant;

//Sends a speed command to a motor channel.
void SendMotorCommand(uint16 rbtq, uint16 port, int motorPower) reentrant;

//Sends motor commands to roboteq.
void SendMultiMotorCommand(uint16 rbtq, int motorPowerL, int motorPowerR) reentrant;

//Extract vector attributes from RC signal
Vector getVectorFromRC();

//Translate the vector attributes to motor commands
void VecToMotors(const Vector* vec);

void SaturateVector(Vector* vec);
void SaturateMottor(Motor* mot);

//Translate the Lateral X RC signal (channel 2) into motor commands
void ProcessX();

//Translate the Lateral Y RC signal (channel 4) into motor commands
void ProcessY();

//Translate the Rotation Z RC signal (channel 1) into motor commands
void ProcessZ();
//----------------------------------------------

//---Globals
//const uint32 timerPeriod = 4294967296; //The max count on the timer
uint16 MaxMag = 60; //empirical
volatile uint16 rcStart = 0;
int16 linearActuatorSetpoint = 0;


uint8 isExtended = 0;
uint8 isRetracted = 1;




enum modes
{
	ESTOP,
	ALLSTOP,
	AUTONOMOUS,
	MANUAL
} mode=ESTOP;

enum adcChannels
{
	VIN = 0,
	ACTUATOR = 1,
	BATT_MOTORS = 2,
	BATT_LOGIC = 3
};

enum digitalPorts
{
	RESET_BUTTON = 5 //from the comparator
};

//Variables for slip
char* pRxData;
char rxDataLength;
uint8 numMotors;
int16 motorThrust[5]= {0,0,0,0,0}; //Motor thrust array indexed by motor ID received from MCU Slip message
uint8 tempMotorID;
int16 tempMotorThrust;

uint8 nerf_fired = 0; // for nerf gun

//define all the rc channels
Channel rcChannels[NUM_CHANNELS] = {{0, 0, 0, {0}, 0}, 
									{0, 0, 0, {0}, 0},
									{0, 0, 0, {0}, 0},
									{0, 0, 0, {0}, 0},
									{0, 0, 0, {0}, 0},
									{0, 0, 0, {0}, 0},
									{0, 0, 0, {0}, 0}};
									
Motor motorFR = {1, 2, 0}; //Front Right
Motor motorFL = {1, 1, 0}; //Front Left
Motor motorBR = {2, 2, 0}; //Back Right
Motor motorBL = {2, 1, 0}; //Back Left
									
const char* SETACCELERATION = "!AC";
const char* SETDECELERATION = "!DC";
const char* SETESTOP = "!EX";
const char* SETESTOPRELEASE = "!MG";
const char* SETSINGLEMOTOR = "!G";
const char* SETMULTIPLEMOTOR = "!M";

const char* QUERYMOTORAMPS = "?A";
const char* QUERYBATTERYAMPS = "?BA";
const char* QUERYTEMP = "?T";
const char* QUERYVOLTS = "?V";
const char* CONFWATCHDOG = "^RWD";

//----------------------------------------------
void RCP(Channel* chn) reentrant
{
	chn->start = Timer_1_ReadCounter();
}

void RCN(Channel* chn) reentrant
{
	chn->end = Timer_1_ReadCounter();
	chn->average = getDifference(chn->start, chn->end);
	//chn->difference[chn->count] = getDifference(chn->start, chn->end);
	//chn->count = (chn->count + 1) % NUM_AVERAGE;
	//chn->average = Average(chn->difference, NUM_AVERAGE);
}

//---------------------------- Channel 1
CY_ISR(RC1PInterruptHandler) {RCP(&rcChannels[0]);}
CY_ISR(RC1NInterruptHandler) {RCN(&rcChannels[0]);}
//---------------------------- Channel 2
CY_ISR(RC2PInterruptHandler) {RCP(&rcChannels[1]);}
CY_ISR(RC2NInterruptHandler) {RCN(&rcChannels[1]);}
//---------------------------- Channel 3
CY_ISR(RC3PInterruptHandler) {RCP(&rcChannels[2]);}
CY_ISR(RC3NInterruptHandler) {RCN(&rcChannels[2]);}
//---------------------------- Channel 4
CY_ISR(RC4PInterruptHandler) {RCP(&rcChannels[3]);}
CY_ISR(RC4NInterruptHandler) {RCN(&rcChannels[3]);}
//---------------------------- Channel 5
CY_ISR(RC5PInterruptHandler) {RCP(&rcChannels[4]);}
CY_ISR(RC5NInterruptHandler) {RCN(&rcChannels[4]);}
//---------------------------- Channel 6
CY_ISR(RC6PInterruptHandler) {RCP(&rcChannels[5]);}
CY_ISR(RC6NInterruptHandler) {RCN(&rcChannels[5]);}
//---------------------------- Channel 7
CY_ISR(RC7PInterruptHandler) {RCP(&rcChannels[6]);}
CY_ISR(RC7NInterruptHandler) {RCN(&rcChannels[6]);}

CY_ISR(RxInterruptHandler)
{
	unsigned char c;
	int numRxData;
	char endReceived = 0;
	int i;
	uint8 rxStatus;

	rxStatus = UART_1_ReadRxStatus();
	if(rxStatus & UART_1_RX_STS_OVERRUN)
	{
		UART_1_ClearRxBuffer();
		return;
	}
	
	//Read all bytes out of UART into rx Data Buffer
	numRxData = UART_1_GetRxBufferSize();
	while(numRxData > 0)
	{
		c = UART_1_ReadRxData();
		bufferPut(&rxDataBuffer, c);
		numRxData--;
		if(c == END)
		{
			endReceived = 1;
		}
	}
	
	if(endReceived)
	{	
		if(SlipProcess(&rxDataBuffer))
		{
			//Valid Slip Packet Received
			rxDataLength = SlipGetRxPacketLength();
			pRxData = SlipGetRxPacketData();
			switch(SlipGetRxPacketType())
			{
				//Ping
				case MCUPing:
					//Respond with Pong
					SendPong();
					break;
				
				//Analog Output
				case MCUSetAnalogOutputs:
					if (pRxData[0] == 0)
					{
						if(mode == AUTONOMOUS)
						{
							linearActuatorSetpoint = CY_GET_REG16(&pRxData[1]);
						}
					}
					break;
				
				//Motor Out Message
				case MCUSetMotorOutput:
					numMotors = pRxData[0];
					for (i = 0; i < numMotors; i++)
					{
						tempMotorID = pRxData[i*3 + 1];
						tempMotorThrust = CY_GET_REG16(&pRxData[i*3 + 2]);
						if (tempMotorID < 5)
							motorThrust[tempMotorID] = tempMotorThrust;
					}
					//Only send motor command if in AUTONOMOUS mode
					if(mode == AUTONOMOUS)
					{
						//SendMotorCommand(motorFL.roboteq, motorFL.port, motorThrust[0]);
						//SendMotorCommand(motorFR.roboteq, motorFR.port, motorThrust[1]);
						//SendMotorCommand(motorBL.roboteq, motorBL.port, motorThrust[2]);
						//SendMotorCommand(motorBR.roboteq, motorBR.port, motorThrust[3]);
                        SendMultiMotorCommand(motorFL.roboteq, motorThrust[0], motorThrust[1]);
                        SendMultiMotorCommand(motorBL.roboteq, motorThrust[2], motorThrust[3]);
                        
						if(motorThrust[4] > 0)
						{
                            if(nerf_fired == 0)
                            {
                                nerf_fire_Write(1); // fire nerf gun
                                nerf_fired = 1;
                            }
							//pump_Write(1);
						}
						else
						{
                            nerf_fired = 0;
						}
					}  
					break;
                case MCULaunchSol:
                    LaunchSol_Write((uint8)pRxData[0]);
                    break;
                case MCUFlagArmCtl:
                    if(pRxData[0] == EXTENDARM && isExtended == 0)
                    {
                        extendArm();
                    }
                    else if(pRxData[0] == RETRACTARM && isRetracted == 0)
                    {
                        retractArm();
                    }
                    else if(pRxData[0] == 0)
                    {
                        stopArm();
                    }
                    break;
			}
		}
	}
}

void extendArm()
{
    /*
    
    */
    isRetracted = 0;
    UART_SABERTOOTH_PutChar(150);
}
void retractArm()
{
    isExtended = 0;
    UART_SABERTOOTH_PutChar(230);
}
void stopArm()
{
    UART_SABERTOOTH_PutChar(0);
}

int32 ReadADC(int channel)
{
	int32 retVal = 0;
	ADC_DelSig_1_StopConvert();
	AMux_1_Select(channel);
	if(channel == ACTUATOR)
	{
		ADC_DelSig_1_SelectConfiguration(2, 0);
	}
	else
	{
		ADC_DelSig_1_SelectConfiguration(1, 0);
	}
	ADC_DelSig_1_Start();
	ADC_DelSig_1_StartConvert();
	if(ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT))
	{
		retVal = ADC_DelSig_1_GetResult32();
	}
	ADC_DelSig_1_StopConvert();
	return retVal;
}


void ControlLinearActuator()
{
	uint16 currentPos;
	int16 error;
	static int16 deadZone = 1;
	int16 output = 64;
	char display[64] = {0};
	
	currentPos = (uint16)ReadADC(ACTUATOR);
	currentPos /= 43;
	error = linearActuatorSetpoint - currentPos;
	
	if(abs(error) > deadZone)
	{
		deadZone = 1;
		output = error;
		if(error < 0)
		{
			output -= 20;
		}
		else
		{
			output += 20;
		}
		if(output > 63)
			output = 63;
		else if(output < -63)
			output = -63;
		output += 64;
	}
	else
	{
		output = 64;
		deadZone = 10;
	}

	if((mode == AUTONOMOUS) || (mode == MANUAL))
	{
		UART_SABERTOOTH_PutChar((uint8)output);
	}
	
	//sprintf(display, "c:%u s:%d e:%d o:%d d:%d\n\r", currentPos, linearActuatorSetpoint, error, output, deadZone);
	//UART_1_PutString(display);
}


float ReadADCVolts(int chn)
{
	int32 value;
	float realVal = 0;
	value = ReadADC(chn);
	switch(chn)
	{
		case VIN:
			realVal = 0.0007999126*value - 0.3156688588;
			break;
	
		case BATT_MOTORS:
			realVal = 0.0008004570*value - 0.3711527009;
			break;
			
		case BATT_LOGIC:
			realVal = 0.0008025596*value - 0.4692905874;
			break;
			
		default:
			realVal = ADC_DelSig_1_CountsTo_Volts(value);
			break;
	}
	return realVal;
}


void DisplayAnalog(int chn, int real)
{
	char display[16];
	if(real)
	{
		sprintf(display, "%.3f V\n\r", ReadADCVolts(chn));
	}
	else
	{
		sprintf(display, "%ld\n\r", ReadADC(chn));
	}
	UART_1_PutString(display);
}


void Report20HzMessages()
{
	static uint32 prevTime = TIMERPERIOD;
	uint32 currTime;
	
	currTime = Timer_1_ReadCounter();
	
	if(getDifference(prevTime, currTime) > 50000)
	{
		//Report MCU Mode: ESTOP, ALLSTOP, AUTONOMOUS, MANUAL
		SendReportAnalogInput(6, mode);
		
		//send the comparator value
		SendReportDigitalInput(RESET_BUTTON, Comp_1_GetCompare());
		
		prevTime = currTime;
	}
}


void Report2HzMessages()
{
	static uint32 prevTime = TIMERPERIOD;
	uint32 currTime;
	uint16 logic_mV, motor_mV;
	float logicVolts, motorVolts;

	currTime = Timer_1_ReadCounter();
	
	if(getDifference(prevTime, currTime) > 500000)
	{
		logicVolts = ReadADCVolts(BATT_LOGIC);
		logicVolts = (logicVolts < 0) ? 0.0 : logicVolts; 
		logic_mV = (uint16)(logicVolts*1000);
		
		motorVolts = ReadADCVolts(BATT_MOTORS);
		motorVolts = (motorVolts < 0) ? 0.0 : motorVolts; 
		motor_mV = (uint16)(motorVolts*1000);
		
		//Report Logic Battery Voltage in millivolts
		SendReportAnalogInput(BATT_LOGIC, logic_mV);
		//Report Motor Battery Voltage in millivolts
		SendReportAnalogInput(BATT_MOTORS, motor_mV);
		
		//Set battery alarm if batteries are below voltage threashold, also make sure greater
		//   than some value to not false alarm when no batteries present.
		//Li-Po min cell voltage = 3.2V, http://en.wikipedia.org/wiki/Lithium-ion_polymer_battery
		//Logic Batteries 6-cell Li-Po 
		//LiFePO4 min cell voltage = 2.8V, http://en.wikipedia.org/wiki/Lithium_iron_phosphate_battery
		//Motor Batteries 4-cell LiFePO4
		if(((logic_mV > 5000) && (logic_mV < 3200*6)) || ((motor_mV > 5000) && (motor_mV < 2800*4)))
		{
			buzzerControl_Write(1);
		}
		else
		{
			buzzerControl_Write(0);
		}
		
		prevTime = currTime;
	}
}

void ReportMessages()
{
	Report20HzMessages();
	Report2HzMessages();
}






void main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	Vector vec;
	
    
	//timerPeriod = Timer_1_ReadPeriod();

	isr_RC1P_StartEx(RC1PInterruptHandler); //Set vector to the proper handler
	isr_RC1N_StartEx(RC1NInterruptHandler); //Set vector to the proper handler
	
	isr_RC2P_StartEx(RC2PInterruptHandler);
	isr_RC2N_StartEx(RC2NInterruptHandler);
	
	isr_RC3P_StartEx(RC3PInterruptHandler);
	isr_RC3N_StartEx(RC3NInterruptHandler);
	
	isr_RC4P_StartEx(RC4PInterruptHandler);
	isr_RC4N_StartEx(RC4NInterruptHandler);
	
	isr_RC5P_StartEx(RC5PInterruptHandler);
	isr_RC5N_StartEx(RC5NInterruptHandler);
	
	isr_RC6P_StartEx(RC6PInterruptHandler);
	isr_RC6N_StartEx(RC6NInterruptHandler);
	
	isr_RC7P_StartEx(RC7PInterruptHandler);
	isr_RC7N_StartEx(RC7NInterruptHandler);
	
	isr_Rx_StartEx(RxInterruptHandler);

    nerf_int_Start();
    ArmRetractedInt_Start();
    ArmExtendedInt_Start();
    
	UART_1_Start(); //Enable the UART
	UART_RBTQ1_Start();
	UART_RBTQ2_Start();
	UART_SABERTOOTH_Start();
	Timer_1_Start(); //Start the timers
	AMux_1_Start();
	ADC_DelSig_1_Start();
	Comp_1_Start();
	
	CyGlobalIntEnable;/* Uncomment this line to enable global interrupts. */
		
        
        
        
	while(1)
    {
        
        /* Place your application code here. */		
		//Add watchdog timeout for serial messages from computer, only when in autonomous mode
		if(rcChannels[4].average < 1500)
		{
			mode = ESTOP;
		}
		else if(rcChannels[2].average > 1702)
		{
			mode = MANUAL;
		}
		else if(rcChannels[2].average < 1276)
		{
			mode = AUTONOMOUS;
		}
		else
		{
			mode = ALLSTOP;
		}
		
		switch(mode)
		{
			case ESTOP:
				strobe_Write(0);//Turn off strobe
				status_1_Write(1);//ESTOP Indicator On
				//SendMotorCommand(motorFL.roboteq, motorFL.port, 0);
				//SendMotorCommand(motorFR.roboteq, motorFR.port, 0);
				//SendMotorCommand(motorBL.roboteq, motorBL.port, 0);
				//SendMotorCommand(motorBR.roboteq, motorBR.port, 0);
                SendMultiMotorCommand(motorFL.roboteq, 0, 0);
                SendMultiMotorCommand(motorBL.roboteq, 0, 0);
				nerf_fire_Write(0);
				UART_SABERTOOTH_PutChar(0x00); //Turn off sabertooth
				break;
				
			case ALLSTOP:
				strobe_Write(0);//Turn off strobe
				status_1_Write(0);//ESTOP Indicator Off
				//SendMotorCommand(motorFL.roboteq, motorFL.port, 0);
				//SendMotorCommand(motorFR.roboteq, motorFR.port, 0);
				//SendMotorCommand(motorBL.roboteq, motorBL.port, 0);
				//SendMotorCommand(motorBR.roboteq, motorBR.port, 0);
                SendMultiMotorCommand(motorFL.roboteq, 0, 0);
                SendMultiMotorCommand(motorBL.roboteq, 0, 0);
				UART_SABERTOOTH_PutChar(0x00); //Turn off sabertooth
				//pump_Write(0);
                nerf_fire_Write(0);
				break;
				
			case AUTONOMOUS:
				strobe_Write(1);//Turn on strobe
				status_1_Write(0);//ESTOP Indicator Off
				//Motor output is event driven in slip messages
				//Pump output is event driven in slip messages
				break;
				
			case MANUAL:
				strobe_Write(0);//Turn off strobe
				status_1_Write(0);//ESTOP Indicator Off
				vec = getVectorFromRC();
				//DisplayVector(vec);
				VecToMotors(&vec);
				//SendMotorCommand(motorFL.roboteq, motorFL.port, motorFL.power);
				//SendMotorCommand(motorFR.roboteq, motorFR.port, motorFR.power);
				//SendMotorCommand(motorBL.roboteq, motorBL.port, motorBL.power);
				//SendMotorCommand(motorBR.roboteq, motorBR.port, motorBR.power);
                SendMultiMotorCommand(motorFL.roboteq, motorFL.power, motorFR.power);
                SendMultiMotorCommand(motorBL.roboteq, motorBL.power, motorBR.power);
				if(rcChannels[6].average < 1245)
				{
					//Control Linear Actuator
					linearActuatorSetpoint = ((int16)rcChannels[5].average) - 875;
				}
                // Nerf channel
				else if(rcChannels[6].average > 1800)
				{
					//Control Nerf
					if(rcChannels[5].average > 1500)
					{
						//pump_Write(1);
                        if(nerf_fired == 0)
                        {
                            nerf_fire_Write(1);
                            nerf_fired = 1;
                        }
                    }
                    else
					{
                        //nerf_fire_Write(0);
    					//pump_Write(0);
                        nerf_fired = 0;
					}
				
				}
				else
				{
					//Control Dynamixel (tilt servo)
				}
				break;
		}
		ControlLinearActuator();
		ReportMessages();
		
		//DisplayChannelValues();
		CyDelay(50); //Run at 20 Hz	
    }
}

//Communicate to the uart the values of the rc channels and print them nicely
void DisplayChannelValues()
{
	int i;
	char display[32] = {0};
	
	//UART_1_PutChar(12); //clear the screen
	for(i = 0; i < NUM_CHANNELS; i++)
	{
		sprintf(display, "%d:%5u ", i, rcChannels[i].average);
		UART_1_PutString(display);
	}
	sprintf(display, "\n\r");
	UART_1_PutString(display);
}

//Display the vector properties to the uart
void DisplayVector(const Vector vec)
{
	char display[64] = {0};
	UART_1_PutChar(12);
	sprintf(display, "%d %d %d\n\r", vec.x, vec.y, vec.r);
	UART_1_PutString(display);
}


//calculate the difference between the first and the second timestamps
uint32 getDifference(uint32 start, uint32 end) reentrant
{
	if(start > end)
	{
		return (start - end);
	}
	else
	{
		return (start + (TIMERPERIOD - end));
		//return (start + (0xFFFF - end));
	}
}

//Sends a speed command to a motor channel.
void SendMotorCommand(uint16 rbtq, uint16 port, int motorPower) reentrant
{
	char message[32];
	//int motorPower = percent * 5;

	sprintf(message,"%s %d %d\r", SETSINGLEMOTOR, port, motorPower);
	
	if(rbtq == 1)
	{
		UART_RBTQ1_PutString(message);
	}
	else if(rbtq == 2)
	{
		UART_RBTQ2_PutString(message);
	}
	else
		return;
}

//Sends a speed command to a motor channel.
void SendMultiMotorCommand(uint16 rbtq, int motorPowerL, int motorPowerR) reentrant
{
	char message[32];
	//int motorPower = percent * 5;

	sprintf(message,"%s %d %d\r", SETMULTIPLEMOTOR, motorPowerL, motorPowerR);
	
	if(rbtq == 1)
	{
		UART_RBTQ1_PutString(message);
	}
	else if(rbtq == 2)
	{
		UART_RBTQ2_PutString(message);
	}
	else
		return;
}

//Extract vector attributes from RC signal
//This converts the RC values from the range [1000us, 2000us] to the range [-1000, 1000]
Vector getVectorFromRC()
{
	Vector vec;
	char display[64] = {0};
    int x = 0;
    int y = 0;
    int r = 0;
    vec.x = 0;
    vec.y = 0;
    vec.r = 0;

	//int x = (rcChannels[1].average / 10 - 150); //channel 2
//	int x = -(rcChannels[1].average / 10 - 150); //channel 2, negative to match JAUS convention (positive linear x pointing forward)
//	int y = (rcChannels[3].average / 10 - 150); //channel 4, positive linear y points right
//	int r = (rcChannels[0].average / 10 - 150); //channel 1, positive rotational z is clockwize

    if (rcChannels[1].average <= (1500 + RCERROR) && rcChannels[1].average >= (1500 - RCERROR))
        vec.x = 0;
    else
    {
        x = -(rcChannels[1].average - 1500) * 2; //channel 2, negative to match JAUS convention (positive linear x pointing forward)
        vec.x = x;
    }
    if (rcChannels[3].average <= (1500 + RCERROR) && rcChannels[3].average >= (1500 - RCERROR))
        vec.y = 0;
    else
    {
        y = (rcChannels[3].average - 1500) * 2; //channel 4, positive linear y points right
        vec.y = y;
    }
    if (rcChannels[0].average <= (1500 + RCERROR) && rcChannels[0].average >= (1500 - RCERROR))
        vec.r = 0;
    else
    {
        r = (rcChannels[0].average - 1500) * 2; //channel 1, positive rotational z is clockwize
        vec.r = r;
    }
    
    SaturateVector(&vec);
	
	//x = -(rcChannels[1].average - 1500) * 2; //channel 2, negative to match JAUS convention (positive linear x pointing forward)
	//y = (rcChannels[3].average - 1500) * 2; //channel 4, positive linear y points right
	//r = (rcChannels[0].average - 1500) * 2; //channel 1, positive rotational z is clockwize
	
	//define RC deadzone
	//if(x >= -RCERROR && x <= RCERROR) x = 0;
	//if(y >= -RCERROR && y <= RCERROR) y = 0;
	//if(r >= -RCERROR && r <= RCERROR) r = 0;
	
	
	//vec.x = x;
	//vec.y = y;
	//vec.r = r;
	
    
	return vec;
}

void SaturateVector(Vector* vec)
{
	if(vec->x < -SATURATION) vec->x = -SATURATION; else if(vec->x > SATURATION) vec->x = SATURATION;
	if(vec->y < -SATURATION) vec->y = -SATURATION; else if(vec->y > SATURATION) vec->y = SATURATION;
	if(vec->r < -SATURATION) vec->r = -SATURATION; else if(vec->r > SATURATION) vec->r = SATURATION;
}

void SaturateMotor(Motor* mot)
{
	if(mot->power < -SATURATION) mot->power = -SATURATION; 
	else if(mot->power > SATURATION) mot->power = SATURATION;
}

//Translate the vector attributes to motor commands
void VecToMotors(const Vector* vec)
{	
	motorFL.power = -vec->x - vec->y - vec->r; SaturateMotor(&motorFL);
	motorFR.power = -vec->x + vec->y + vec->r; SaturateMotor(&motorFR);
	motorBL.power = vec->x - vec->y + vec->r; SaturateMotor(&motorBL);
	motorBR.power = vec->x + vec->y - vec->r; SaturateMotor(&motorBR);
}




















