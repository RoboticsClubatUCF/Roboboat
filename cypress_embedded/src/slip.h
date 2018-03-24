#ifndef SLIP_H
#define SLIP_H

#include "buffer.h"
#include "UART_1.h"
// This determines the size of the Packet Receive Buffer
// where whole verified packets are copied after being received
#define MAXRXPACKETSIZE	256	// length of packet buffer

// constants
#define END 192
#define ESC 219
#define ESC_END 220
#define ESC_ESC 221

#define HEADER_LENGTH 2
#define TRAILER_LENGTH 1

#define LENGTH_OFFSET 0
#define TYPE_OFFSET 1
#define DATA_OFFSET 2
#define CHECKSUM_OFFSET 3

enum MessageCodes
{
	MCUQueryReport           = 0x00,       
    MCUPing                  = 0x0D,       

    MCUSetServoOutputs       = 0x0B,
    MCUSetDigitalOutputs     = 0x0C,
    MCUSetAnalogOutputs      = 0x0E,
    MCUSetMotorOutput        = 0x0F,
    
    MCUNerfStatus            = 0x80,
    MCULaunchSol             = 0x81,
    MCUFlagArmCtl            = 0x86,
    
    MCUReportDigitalInputs   = 0x82,
    MCUReportAnalogInputs    = 0x83,
    MCUPong                  = 0x84, 
    MCUReportEncoders        = 0x85,

    MCUReportID              = 0x8F
};

// function prototypes

void SendMessage(unsigned char type, unsigned char* dataptr, unsigned char datalength) reentrant;

//! Send data within a Slip Frame
void SlipSend(unsigned char* dataptr, unsigned char length) reentrant;

//! Process a buffer containing slip frame
unsigned char SlipProcess(cBuffer* rxBuffer);

//! Returns the received packet's type
unsigned char SlipGetRxPacketType(void);

//! Returns the received packet's datalength
unsigned char SlipGetRxPacketLength(void);

//! Returns pointer to the received packet's data
unsigned char* SlipGetRxPacketData(void);

//Send Message Functions
void SendPong() reentrant;
void SendReportAnalogInput(uint8 port, uint16 value) reentrant;
void SendReportDigitalInput(uint8 port, uint8 value) reentrant;
void SendNerfStatus(uint8 status) reentrant;


#endif
