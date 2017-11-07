/*******************************************************************************
* File Name: BATT_MOTOR.c  
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
#include "BATT_MOTOR.h"


/*******************************************************************************
* Function Name: BATT_MOTOR_Write
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
void BATT_MOTOR_Write(uint8 value) 
{
    uint8 staticBits = (BATT_MOTOR_DR & (uint8)(~BATT_MOTOR_MASK));
    BATT_MOTOR_DR = staticBits | ((uint8)(value << BATT_MOTOR_SHIFT) & BATT_MOTOR_MASK);
}


/*******************************************************************************
* Function Name: BATT_MOTOR_SetDriveMode
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
void BATT_MOTOR_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BATT_MOTOR_0, mode);
}


/*******************************************************************************
* Function Name: BATT_MOTOR_Read
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
*  Macro BATT_MOTOR_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BATT_MOTOR_Read(void) 
{
    return (BATT_MOTOR_PS & BATT_MOTOR_MASK) >> BATT_MOTOR_SHIFT;
}


/*******************************************************************************
* Function Name: BATT_MOTOR_ReadDataReg
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
uint8 BATT_MOTOR_ReadDataReg(void) 
{
    return (BATT_MOTOR_DR & BATT_MOTOR_MASK) >> BATT_MOTOR_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BATT_MOTOR_INTSTAT) 

    /*******************************************************************************
    * Function Name: BATT_MOTOR_ClearInterrupt
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
    uint8 BATT_MOTOR_ClearInterrupt(void) 
    {
        return (BATT_MOTOR_INTSTAT & BATT_MOTOR_MASK) >> BATT_MOTOR_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
