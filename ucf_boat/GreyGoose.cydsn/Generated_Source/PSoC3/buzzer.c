/*******************************************************************************
* File Name: buzzer.c  
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
#include "buzzer.h"


/*******************************************************************************
* Function Name: buzzer_Write
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
void buzzer_Write(uint8 value) 
{
    uint8 staticBits = (buzzer_DR & (uint8)(~buzzer_MASK));
    buzzer_DR = staticBits | ((uint8)(value << buzzer_SHIFT) & buzzer_MASK);
}


/*******************************************************************************
* Function Name: buzzer_SetDriveMode
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
void buzzer_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(buzzer_0, mode);
}


/*******************************************************************************
* Function Name: buzzer_Read
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
*  Macro buzzer_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 buzzer_Read(void) 
{
    return (buzzer_PS & buzzer_MASK) >> buzzer_SHIFT;
}


/*******************************************************************************
* Function Name: buzzer_ReadDataReg
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
uint8 buzzer_ReadDataReg(void) 
{
    return (buzzer_DR & buzzer_MASK) >> buzzer_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(buzzer_INTSTAT) 

    /*******************************************************************************
    * Function Name: buzzer_ClearInterrupt
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
    uint8 buzzer_ClearInterrupt(void) 
    {
        return (buzzer_INTSTAT & buzzer_MASK) >> buzzer_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
