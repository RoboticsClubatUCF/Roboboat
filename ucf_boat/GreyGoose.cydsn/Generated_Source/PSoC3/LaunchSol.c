/*******************************************************************************
* File Name: LaunchSol.c  
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
#include "LaunchSol.h"


/*******************************************************************************
* Function Name: LaunchSol_Write
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
void LaunchSol_Write(uint8 value) 
{
    uint8 staticBits = (LaunchSol_DR & (uint8)(~LaunchSol_MASK));
    LaunchSol_DR = staticBits | ((uint8)(value << LaunchSol_SHIFT) & LaunchSol_MASK);
}


/*******************************************************************************
* Function Name: LaunchSol_SetDriveMode
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
void LaunchSol_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LaunchSol_0, mode);
}


/*******************************************************************************
* Function Name: LaunchSol_Read
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
*  Macro LaunchSol_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LaunchSol_Read(void) 
{
    return (LaunchSol_PS & LaunchSol_MASK) >> LaunchSol_SHIFT;
}


/*******************************************************************************
* Function Name: LaunchSol_ReadDataReg
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
uint8 LaunchSol_ReadDataReg(void) 
{
    return (LaunchSol_DR & LaunchSol_MASK) >> LaunchSol_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LaunchSol_INTSTAT) 

    /*******************************************************************************
    * Function Name: LaunchSol_ClearInterrupt
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
    uint8 LaunchSol_ClearInterrupt(void) 
    {
        return (LaunchSol_INTSTAT & LaunchSol_MASK) >> LaunchSol_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
