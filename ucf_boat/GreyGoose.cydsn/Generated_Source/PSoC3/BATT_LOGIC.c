/*******************************************************************************
* File Name: BATT_LOGIC.c  
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
#include "BATT_LOGIC.h"


/*******************************************************************************
* Function Name: BATT_LOGIC_Write
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
void BATT_LOGIC_Write(uint8 value) 
{
    uint8 staticBits = (BATT_LOGIC_DR & (uint8)(~BATT_LOGIC_MASK));
    BATT_LOGIC_DR = staticBits | ((uint8)(value << BATT_LOGIC_SHIFT) & BATT_LOGIC_MASK);
}


/*******************************************************************************
* Function Name: BATT_LOGIC_SetDriveMode
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
void BATT_LOGIC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BATT_LOGIC_0, mode);
}


/*******************************************************************************
* Function Name: BATT_LOGIC_Read
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
*  Macro BATT_LOGIC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BATT_LOGIC_Read(void) 
{
    return (BATT_LOGIC_PS & BATT_LOGIC_MASK) >> BATT_LOGIC_SHIFT;
}


/*******************************************************************************
* Function Name: BATT_LOGIC_ReadDataReg
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
uint8 BATT_LOGIC_ReadDataReg(void) 
{
    return (BATT_LOGIC_DR & BATT_LOGIC_MASK) >> BATT_LOGIC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BATT_LOGIC_INTSTAT) 

    /*******************************************************************************
    * Function Name: BATT_LOGIC_ClearInterrupt
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
    uint8 BATT_LOGIC_ClearInterrupt(void) 
    {
        return (BATT_LOGIC_INTSTAT & BATT_LOGIC_MASK) >> BATT_LOGIC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
