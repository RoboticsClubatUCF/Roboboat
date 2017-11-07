/*******************************************************************************
* File Name: nerf_reed.c  
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
#include "nerf_reed.h"


/*******************************************************************************
* Function Name: nerf_reed_Write
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
void nerf_reed_Write(uint8 value) 
{
    uint8 staticBits = (nerf_reed_DR & (uint8)(~nerf_reed_MASK));
    nerf_reed_DR = staticBits | ((uint8)(value << nerf_reed_SHIFT) & nerf_reed_MASK);
}


/*******************************************************************************
* Function Name: nerf_reed_SetDriveMode
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
void nerf_reed_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(nerf_reed_0, mode);
}


/*******************************************************************************
* Function Name: nerf_reed_Read
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
*  Macro nerf_reed_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 nerf_reed_Read(void) 
{
    return (nerf_reed_PS & nerf_reed_MASK) >> nerf_reed_SHIFT;
}


/*******************************************************************************
* Function Name: nerf_reed_ReadDataReg
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
uint8 nerf_reed_ReadDataReg(void) 
{
    return (nerf_reed_DR & nerf_reed_MASK) >> nerf_reed_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(nerf_reed_INTSTAT) 

    /*******************************************************************************
    * Function Name: nerf_reed_ClearInterrupt
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
    uint8 nerf_reed_ClearInterrupt(void) 
    {
        return (nerf_reed_INTSTAT & nerf_reed_MASK) >> nerf_reed_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
