/*******************************************************************************
* File Name: Reset_Ref.c  
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
#include "Reset_Ref.h"


/*******************************************************************************
* Function Name: Reset_Ref_Write
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
void Reset_Ref_Write(uint8 value) 
{
    uint8 staticBits = (Reset_Ref_DR & (uint8)(~Reset_Ref_MASK));
    Reset_Ref_DR = staticBits | ((uint8)(value << Reset_Ref_SHIFT) & Reset_Ref_MASK);
}


/*******************************************************************************
* Function Name: Reset_Ref_SetDriveMode
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
void Reset_Ref_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Reset_Ref_0, mode);
}


/*******************************************************************************
* Function Name: Reset_Ref_Read
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
*  Macro Reset_Ref_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Reset_Ref_Read(void) 
{
    return (Reset_Ref_PS & Reset_Ref_MASK) >> Reset_Ref_SHIFT;
}


/*******************************************************************************
* Function Name: Reset_Ref_ReadDataReg
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
uint8 Reset_Ref_ReadDataReg(void) 
{
    return (Reset_Ref_DR & Reset_Ref_MASK) >> Reset_Ref_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Reset_Ref_INTSTAT) 

    /*******************************************************************************
    * Function Name: Reset_Ref_ClearInterrupt
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
    uint8 Reset_Ref_ClearInterrupt(void) 
    {
        return (Reset_Ref_INTSTAT & Reset_Ref_MASK) >> Reset_Ref_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
