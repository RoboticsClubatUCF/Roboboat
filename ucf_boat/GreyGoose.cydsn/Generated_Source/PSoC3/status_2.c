/*******************************************************************************
* File Name: status_2.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "status_2.h"


/*******************************************************************************
* Function Name: status_2_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void status_2_Write(uint8 value) 
{
    uint8 staticBits = (status_2_DR & (uint8)(~status_2_MASK));
    status_2_DR = staticBits | ((uint8)(value << status_2_SHIFT) & status_2_MASK);
}


/*******************************************************************************
* Function Name: status_2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void status_2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(status_2_0, mode);
}


/*******************************************************************************
* Function Name: status_2_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro status_2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 status_2_Read(void) 
{
    return (status_2_PS & status_2_MASK) >> status_2_SHIFT;
}


/*******************************************************************************
* Function Name: status_2_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 status_2_ReadDataReg(void) 
{
    return (status_2_DR & status_2_MASK) >> status_2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(status_2_INTSTAT) 

    /*******************************************************************************
    * Function Name: status_2_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 status_2_ClearInterrupt(void) 
    {
        return (status_2_INTSTAT & status_2_MASK) >> status_2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
