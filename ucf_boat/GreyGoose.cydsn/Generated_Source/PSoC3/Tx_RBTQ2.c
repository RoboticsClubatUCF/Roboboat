/*******************************************************************************
* File Name: Tx_RBTQ2.c  
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
#include "Tx_RBTQ2.h"


/*******************************************************************************
* Function Name: Tx_RBTQ2_Write
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
void Tx_RBTQ2_Write(uint8 value) 
{
    uint8 staticBits = (Tx_RBTQ2_DR & (uint8)(~Tx_RBTQ2_MASK));
    Tx_RBTQ2_DR = staticBits | ((uint8)(value << Tx_RBTQ2_SHIFT) & Tx_RBTQ2_MASK);
}


/*******************************************************************************
* Function Name: Tx_RBTQ2_SetDriveMode
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
void Tx_RBTQ2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Tx_RBTQ2_0, mode);
}


/*******************************************************************************
* Function Name: Tx_RBTQ2_Read
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
*  Macro Tx_RBTQ2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Tx_RBTQ2_Read(void) 
{
    return (Tx_RBTQ2_PS & Tx_RBTQ2_MASK) >> Tx_RBTQ2_SHIFT;
}


/*******************************************************************************
* Function Name: Tx_RBTQ2_ReadDataReg
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
uint8 Tx_RBTQ2_ReadDataReg(void) 
{
    return (Tx_RBTQ2_DR & Tx_RBTQ2_MASK) >> Tx_RBTQ2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Tx_RBTQ2_INTSTAT) 

    /*******************************************************************************
    * Function Name: Tx_RBTQ2_ClearInterrupt
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
    uint8 Tx_RBTQ2_ClearInterrupt(void) 
    {
        return (Tx_RBTQ2_INTSTAT & Tx_RBTQ2_MASK) >> Tx_RBTQ2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
