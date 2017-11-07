/*******************************************************************************
* File Name: ArmRetractedInt.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <ArmRetractedInt.H>

#if !defined(ArmRetractedInt__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ArmRetractedInt_intc` */
extern uint8 isExtended;
extern uint8 isRetracted;
extern void UART_SABERTOOTH_PutChar(uint8);
/* `#END` */


/*******************************************************************************
* Function Name: ArmRetractedInt_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_Start(void) 
{
    /* For all we know the interrupt is active. */
    ArmRetractedInt_Disable();

    /* Set the ISR to point to the ArmRetractedInt Interrupt. */
    ArmRetractedInt_SetVector(&ArmRetractedInt_Interrupt);

    /* Set the priority. */
    ArmRetractedInt_SetPriority((uint8)ArmRetractedInt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ArmRetractedInt_Enable();
}


/*******************************************************************************
* Function Name: ArmRetractedInt_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_StartEx(cyisraddress address) 
{
    /* For all we know the interrupt is active. */
    ArmRetractedInt_Disable();

    /* Set the ISR to point to the ArmRetractedInt Interrupt. */
    ArmRetractedInt_SetVector(address);

    /* Set the priority. */
    ArmRetractedInt_SetPriority((uint8)ArmRetractedInt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ArmRetractedInt_Enable();
}


/*******************************************************************************
* Function Name: ArmRetractedInt_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_Stop(void) 
{
    /* Disable this interrupt. */
    ArmRetractedInt_Disable();
}


/*******************************************************************************
* Function Name: ArmRetractedInt_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for ArmRetractedInt.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(ArmRetractedInt_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ArmRetractedInt_Interrupt` */
    isRetracted = 1;
    isExtended = 0;
    UART_SABERTOOTH_PutChar(0);


    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (ArmRetractedInt__ES2_PATCH ))      
            ArmRetractedInt_ISR_PATCH();
        #endif /* CYDEV_CHIP_REVISION_USED */
    #endif /* (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */
}


/*******************************************************************************
* Function Name: ArmRetractedInt_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ArmRetractedInt_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ArmRetractedInt_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_SetVector(cyisraddress address) 
{
    CY_SET_REG16(ArmRetractedInt_INTC_VECTOR, (uint16) address);
}


/*******************************************************************************
* Function Name: ArmRetractedInt_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress ArmRetractedInt_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(ArmRetractedInt_INTC_VECTOR);
}


/*******************************************************************************
* Function Name: ArmRetractedInt_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ArmRetractedInt_Start
*   or ArmRetractedInt_StartEx will override any effect this method would 
*   have had. This method should only be called after ArmRetractedInt_Start or 
*   ArmRetractedInt_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_SetPriority(uint8 priority) 
{
    *ArmRetractedInt_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: ArmRetractedInt_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*******************************************************************************/
uint8 ArmRetractedInt_GetPriority(void) 
{
    uint8 priority;


    priority = *ArmRetractedInt_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: ArmRetractedInt_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_Enable(void) 
{
    /* Enable the general interrupt. */
    *ArmRetractedInt_INTC_SET_EN = ArmRetractedInt__INTC_MASK;
}


/*******************************************************************************
* Function Name: ArmRetractedInt_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 ArmRetractedInt_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return ((*ArmRetractedInt_INTC_SET_EN & (uint8)ArmRetractedInt__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ArmRetractedInt_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_Disable(void) 
{
    /* Disable the general interrupt. */
    *ArmRetractedInt_INTC_CLR_EN = ArmRetractedInt__INTC_MASK;
}


/*******************************************************************************
* Function Name: ArmRetractedInt_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_SetPending(void) 
{
    *ArmRetractedInt_INTC_SET_PD = ArmRetractedInt__INTC_MASK;
}


/*******************************************************************************
* Function Name: ArmRetractedInt_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ArmRetractedInt_ClearPending(void) 
{
    *ArmRetractedInt_INTC_CLR_PD = ArmRetractedInt__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
