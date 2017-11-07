/*******************************************************************************
* File Name: ArmExtended_switch.c  
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
#include "ArmExtended_switch.h"


/*******************************************************************************
* Function Name: ArmExtended_switch_Write
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
void ArmExtended_switch_Write(uint8 value) 
{
    uint8 staticBits = (ArmExtended_switch_DR & (uint8)(~ArmExtended_switch_MASK));
    ArmExtended_switch_DR = staticBits | ((uint8)(value << ArmExtended_switch_SHIFT) & ArmExtended_switch_MASK);
}


/*******************************************************************************
* Function Name: ArmExtended_switch_SetDriveMode
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
void ArmExtended_switch_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ArmExtended_switch_0, mode);
}


/*******************************************************************************
* Function Name: ArmExtended_switch_Read
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
*  Macro ArmExtended_switch_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ArmExtended_switch_Read(void) 
{
    return (ArmExtended_switch_PS & ArmExtended_switch_MASK) >> ArmExtended_switch_SHIFT;
}


/*******************************************************************************
* Function Name: ArmExtended_switch_ReadDataReg
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
uint8 ArmExtended_switch_ReadDataReg(void) 
{
    return (ArmExtended_switch_DR & ArmExtended_switch_MASK) >> ArmExtended_switch_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ArmExtended_switch_INTSTAT) 

    /*******************************************************************************
    * Function Name: ArmExtended_switch_ClearInterrupt
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
    uint8 ArmExtended_switch_ClearInterrupt(void) 
    {
        return (ArmExtended_switch_INTSTAT & ArmExtended_switch_MASK) >> ArmExtended_switch_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
