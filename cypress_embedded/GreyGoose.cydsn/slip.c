#include "slip.h"
#include <string.h>

// received packet data buffer
unsigned char slipRxFrame[MAXRXPACKETSIZE];


void SendPong() reentrant
{
	SendMessage(MCUPong, (unsigned char*)"PONG", 4);
}


void SendReportAnalogInput(uint8 port, uint16 value) reentrant
{
	char txBuffer[16];
	uint16 leValue;
	
	memcpy(txBuffer, &port, sizeof(port));
	// Convert to little endian byte order
	CY_SET_REG16(&leValue, value);
	memcpy(txBuffer + 1, &leValue, sizeof(leValue)); 
	
	SendMessage(MCUReportAnalogInputs, txBuffer, 3);
}

void SendNerfStatus(uint8 status) reentrant
{
    char txBuffer[16];
    memcpy(txBuffer, &status, sizeof(status));
    
    SendMessage(MCUNerfStatus, &status, 1);
}


void SendReportDigitalInput(uint8 port, uint8 value) reentrant
{
	char txBuffer[16];
	
	memcpy(txBuffer, &port, sizeof(port));
	memcpy(txBuffer + 1, &value, sizeof(value)); 
	
	SendMessage(MCUReportDigitalInputs, txBuffer, 2);
}


void SendMessage(unsigned char type, unsigned char* dataptr, unsigned char datalength) reentrant
{
    unsigned char length = datalength + HEADER_LENGTH + TRAILER_LENGTH;
    unsigned char packet[64];
    unsigned int i;
    unsigned char checksum = 0;
    
    checksum += packet[0] = length;
    checksum += packet[1] = type;
    for(i=0; i<datalength; i++)
    {
        checksum += packet[i+DATA_OFFSET] = dataptr[i];
    }
    packet[length-1] = checksum;
    SlipSend(packet, length);
}

// Send data inside Slip frame
void SlipSend(unsigned char* dataptr, unsigned char length) reentrant
{
    unsigned int i;
    
    UART_1_PutChar(END);
    for(i=0; i<length; i++)
    {
        switch(dataptr[i])
        {
            case END:
                UART_1_PutChar(ESC);
                UART_1_PutChar(ESC_END);
                break;
            
            case ESC:
                UART_1_PutChar(ESC);
                UART_1_PutChar(ESC_ESC);
                break;
                
            default:
                UART_1_PutChar(dataptr[i]);
                break;
        }
    }
    UART_1_PutChar(END);
}

// process buffer containing Slip frame
unsigned char SlipProcess(cBuffer* rxBuffer)
{
    unsigned char c;
    unsigned int received = 0;
    unsigned int i = 0;
    unsigned char receivedMessage = 0;
	unsigned char messageLength;
    unsigned char checksum;
	
    if(rxBuffer->datalength >= HEADER_LENGTH + TRAILER_LENGTH)
    {
        for(i=0; i<rxBuffer->datalength; i++)
        {
			c = bufferGetAtIndex(rxBuffer, i);
            if(c == END)
            {
                //Found END character within buffer, indicates complete frame
                if(i == 0)
                {
                    //Ignores END if at 0 index
                    continue;
                }
                break;
            }
            if(i == rxBuffer->datalength - 1)
            {
                //Reached end of buffer without END, no complete frame
                if(bufferIsFull(rxBuffer))
                {
                    //Buffer is full without frame, flush
                    bufferFlush(rxBuffer);
                }
                return 0;
            }
        }

        while(rxBuffer->datalength && !receivedMessage)
        {
            bufferGet(rxBuffer, &c);
            switch(c)
            {
                case END:
                    if(received)
                    {
                        receivedMessage = 1;
                        //return received;
                    }
                    break;
                
                case ESC:
                    bufferGet(rxBuffer, &c);
                    switch(c)
                    {
                        case ESC_END:
                            c = END;
                            break;
                        case ESC_ESC:
                            c = ESC;
                            break;
                    }
                
                default:
                    slipRxFrame[received++] = c;
            }
        }
        
        //Check received message length and checksum
        messageLength = slipRxFrame[LENGTH_OFFSET];
        checksum = 0;
        if(messageLength == received)
        {
            //Valid length
            for(i=0; i<messageLength-1; i++)
            {
                checksum += slipRxFrame[i];
            }
            if(checksum == slipRxFrame[messageLength-1])
            {
                //Valid checksum
                return received;
            }
        }
    }
    //Invalid Message
    return 0;
}

unsigned char SlipGetRxPacketType(void)
{
	// return the packet's type
	return slipRxFrame[TYPE_OFFSET];
}

unsigned char SlipGetRxPacketLength(void)
{
	// return the packet's datalength
	return slipRxFrame[LENGTH_OFFSET];
}

unsigned char* SlipGetRxPacketData(void)
{
	// return a pointer to the packet's data payload
	return slipRxFrame+DATA_OFFSET;
}


