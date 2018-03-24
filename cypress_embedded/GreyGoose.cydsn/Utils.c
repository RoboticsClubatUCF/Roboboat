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

#include "Utils.h"

//hash table for translating a nibble into its equivalent hex character
const char output[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

//Compute the average of an array
uint16 Average(const uint16 a[], uint16 size)
{
	uint32 sum = 0;
	uint16 i;
	for(i = 0; i < size; i++)
	{
		sum += a[i];
	}
	return (uint16)(sum / size);
}

//Convert a uint16 into a hex string
char* UInt16ToString(uint16 num)
{
	char* ptr = (char*)(&num);
	int i, j;
	char str[5] = {'\0'};
	
	for(i = 0, j = 0; i < sizeof(num) && j < 5; i++)
	{
		str[j++] = output[(*(ptr+i) >> 4) & 0x0F];		
		str[j++] = output[*(ptr+i) & 0x0F];
	}
	
	return str;
}

/* [] END OF FILE */
