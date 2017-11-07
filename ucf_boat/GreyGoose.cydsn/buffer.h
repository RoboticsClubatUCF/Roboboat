#ifndef _BUFFER_H_
#define _BUFFER_H_

// structure/type defs
typedef struct struct_cBuffer{
	unsigned char*	dataptr;		// the physical memory address where the buffer is stored
	unsigned char 		size;				// the allocated size of the buffer
	unsigned char 		datalength;			// the length of the data currently in the buffer
	unsigned char 		dataindex;			// the index into the buffer where the data starts
} cBuffer;

// Constructor
#define MAKE_BUFFER(bytes) {bytes,sizeof(bytes),0,0}


// function prototypes

// initialize a buffer to start at a given address and have given size
void bufferInit(cBuffer* buffer, unsigned char *start, unsigned char size);
unsigned char bufferGet(cBuffer* buffer, unsigned char* rtn);


// dump (discard) the first numbytes from the front of the buffer
void bufferDump(cBuffer* buffer, unsigned char numbytes);

// get a byte at the specified index in the buffer (kind of like array access)
// ** note: this does not remove the byte that was read from the buffer
unsigned char bufferGetAtIndex(const cBuffer* buffer, unsigned char index);

// add a byte to the end of the buffer
unsigned char bufferPut(cBuffer* buffer, unsigned char character);

unsigned char bufferIsFull(const cBuffer* buffer);

// flush (clear) the contents of the buffer
void bufferFlush(cBuffer* buffer);

// How many bytes are free in the buffer
unsigned char bufferFreeSpace(const cBuffer* buffer);

// The number of used bytes in the buffer
unsigned char bufferBytesUsed(const cBuffer* buffer);
#endif
