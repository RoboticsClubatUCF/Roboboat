/*******************************************************************************
* File Name: Actuator.c  
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
#include "Actuator.h"


/*******************************************************************************
* Function Name: Actuator_Write
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
void Actuator_Write(uint8 value) 
{
    uint8 staticBits = (Actuator_DR & (uint8)(~Actuator_MASK));
    Actuator_DR = staticBits | ((uint8)(value << Actuator_SHIFT) & Actuator_MASK);
}


/*******************************************************************************
* Function Name: Actuator_SetDriveMode
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
void Actuator_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Actuator_0, mode);
}


/*******************************************************************************
* Function Name: Actuator_Read
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
*  Macro Actuator_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Actuator_Read(void) 
{
    return (Actuator_PS & Actuator_MASK) >> Actuator_SHIFT;
}


/*******************************************************************************
* Function Name: Actuator_ReadDataReg
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
uint8 Actuator_ReadDataReg(void) 
{
    return (Actuator_DR & Actuator_MASK) >> Actuator_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Actuator_INTSTAT) 

    /*******************************************************************************
    * Function Name: Actuator_ClearInterrupt
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
    uint8 Actuator_ClearInterrupt(void) 
    {
        return (Actuator_INTSTAT & Actuator_MASK) >> Actuator_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
