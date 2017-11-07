/*******************************************************************************
* File Name: VIN.c  
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
#include "VIN.h"


/*******************************************************************************
* Function Name: VIN_Write
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
void VIN_Write(uint8 value) 
{
    uint8 staticBits = (VIN_DR & (uint8)(~VIN_MASK));
    VIN_DR = staticBits | ((uint8)(value << VIN_SHIFT) & VIN_MASK);
}


/*******************************************************************************
* Function Name: VIN_SetDriveMode
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
void VIN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VIN_0, mode);
}


/*******************************************************************************
* Function Name: VIN_Read
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
*  Macro VIN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VIN_Read(void) 
{
    return (VIN_PS & VIN_MASK) >> VIN_SHIFT;
}


/*******************************************************************************
* Function Name: VIN_ReadDataReg
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
uint8 VIN_ReadDataReg(void) 
{
    return (VIN_DR & VIN_MASK) >> VIN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VIN_INTSTAT) 

    /*******************************************************************************
    * Function Name: VIN_ClearInterrupt
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
    uint8 VIN_ClearInterrupt(void) 
    {
        return (VIN_INTSTAT & VIN_MASK) >> VIN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
