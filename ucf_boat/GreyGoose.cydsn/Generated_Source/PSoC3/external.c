/*******************************************************************************
* File Name: external.c  
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
#include "external.h"


/*******************************************************************************
* Function Name: external_Write
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
void external_Write(uint8 value) 
{
    uint8 staticBits = (external_DR & (uint8)(~external_MASK));
    external_DR = staticBits | ((uint8)(value << external_SHIFT) & external_MASK);
}


/*******************************************************************************
* Function Name: external_SetDriveMode
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
void external_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(external_0, mode);
}


/*******************************************************************************
* Function Name: external_Read
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
*  Macro external_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 external_Read(void) 
{
    return (external_PS & external_MASK) >> external_SHIFT;
}


/*******************************************************************************
* Function Name: external_ReadDataReg
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
uint8 external_ReadDataReg(void) 
{
    return (external_DR & external_MASK) >> external_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(external_INTSTAT) 

    /*******************************************************************************
    * Function Name: external_ClearInterrupt
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
    uint8 external_ClearInterrupt(void) 
    {
        return (external_INTSTAT & external_MASK) >> external_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
