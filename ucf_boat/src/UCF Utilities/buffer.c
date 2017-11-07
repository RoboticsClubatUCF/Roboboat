#include "buffer.h"

// initialize a buffer to start at a given address and have given size
void bufferInit(cBuffer* buffer, unsigned char* start, unsigned char size){
	buffer->dataptr = start;
	buffer->size = size;
	buffer->dataindex = buffer->datalength = 0;
}


unsigned char bufferGet(cBuffer* buffer, unsigned char* rtn){
	unsigned char ok = 0;
	if(buffer && buffer->size){
		// make sure we have data
		if(buffer->datalength){
			// get the first character from buffer
			*rtn = buffer->dataptr[buffer->dataindex];
			// move index down and decrement length
			buffer->dataindex = (buffer->dataindex + 1) % buffer->size;
			buffer->datalength--;
			ok = 1;
		}
	}
	return ok;
}

unsigned char bufferGetAtIndex(const cBuffer* buffer, unsigned char index){
	unsigned char c;
	// return character at index in buffer
	c = (buffer) ? buffer->dataptr[(buffer->dataindex+index)%(buffer->size)] : 0;
	return c;
}

// add a byte to the end of the buffer
unsigned char bufferPut(cBuffer* buffer, unsigned char c){
	unsigned char rtn = 0; // failure
	// make sure the buffer has room
	if(buffer->datalength < buffer->size)
	{
		// save data byte at end of buffer
		buffer->dataptr[(buffer->dataindex + buffer->datalength) % buffer->size] = c;
		// increment the length
		buffer->datalength++;
		// return success
		rtn = 1;
	}
	return rtn;
}

unsigned char bufferFreeSpace(const cBuffer* buffer){
	unsigned char rtn;
	rtn =  (buffer) ? buffer->size - buffer->datalength : 0;
	return rtn;
}

unsigned char bufferBytesUsed(const cBuffer* buffer){
	unsigned char rtn;
	rtn =  (buffer) ? buffer->datalength : 0;
	return rtn;
}

unsigned char bufferIsFull(const cBuffer* buffer){
	return (bufferFreeSpace(buffer)==0) ? 1 : 0;
}

// flush (clear) the contents of the buffer
void bufferFlush(cBuffer* buffer){
	if(buffer){
		// flush contents of the buffer
		buffer->datalength = 0;
	}
}
