/*******************************************************************************
* File Name: TestPin.c  
* Version 1.60
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "TestPin.h"


/*******************************************************************************
* Function Name: TestPin_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void TestPin_Write(uint8 value) 
{
    uint8 staticBits = TestPin_DR & ~TestPin_MASK;
    TestPin_DR = staticBits | ((value << TestPin_SHIFT) & TestPin_MASK);
}


/*******************************************************************************
* Function Name: TestPin_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void TestPin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TestPin_0, mode);
}


/*******************************************************************************
* Function Name: TestPin_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro TestPin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TestPin_Read(void) 
{
    return (TestPin_PS & TestPin_MASK) >> TestPin_SHIFT;
}


/*******************************************************************************
* Function Name: TestPin_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 TestPin_ReadDataReg(void) 
{
    return (TestPin_DR & TestPin_MASK) >> TestPin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TestPin_INTSTAT) 

    /*******************************************************************************
    * Function Name: TestPin_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 TestPin_ClearInterrupt(void) 
    {
        return (TestPin_INTSTAT & TestPin_MASK) >> TestPin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
