/*******************************************************************************
* File Name: ArmExtendedInt.c  
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
#include <ArmExtendedInt.H>

#if !defined(ArmExtendedInt__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ArmExtendedInt_intc` */
extern uint8 isExtended;
extern uint8 isRetracted;
extern void UART_SABERTOOTH_PutChar(uint8);
/* `#END` */


/*******************************************************************************
* Function Name: ArmExtendedInt_Start
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
void ArmExtendedInt_Start(void) 
{
    /* For all we know the interrupt is active. */
    ArmExtendedInt_Disable();

    /* Set the ISR to point to the ArmExtendedInt Interrupt. */
    ArmExtendedInt_SetVector(&ArmExtendedInt_Interrupt);

    /* Set the priority. */
    ArmExtendedInt_SetPriority((uint8)ArmExtendedInt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ArmExtendedInt_Enable();
}


/*******************************************************************************
* Function Name: ArmExtendedInt_StartEx
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
void ArmExtendedInt_StartEx(cyisraddress address) 
{
    /* For all we know the interrupt is active. */
    ArmExtendedInt_Disable();

    /* Set the ISR to point to the ArmExtendedInt Interrupt. */
    ArmExtendedInt_SetVector(address);

    /* Set the priority. */
    ArmExtendedInt_SetPriority((uint8)ArmExtendedInt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ArmExtendedInt_Enable();
}


/*******************************************************************************
* Function Name: ArmExtendedInt_Stop
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
void ArmExtendedInt_Stop(void) 
{
    /* Disable this interrupt. */
    ArmExtendedInt_Disable();
}


/*******************************************************************************
* Function Name: ArmExtendedInt_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for ArmExtendedInt.
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
CY_ISR(ArmExtendedInt_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ArmExtendedInt_Interrupt` */

    isRetracted = 0;
    isExtended = 1;
    UART_SABERTOOTH_PutChar(0);


    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (ArmExtendedInt__ES2_PATCH ))      
            ArmExtendedInt_ISR_PATCH();
        #endif /* CYDEV_CHIP_REVISION_USED */
    #endif /* (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */
}


/*******************************************************************************
* Function Name: ArmExtendedInt_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ArmExtendedInt_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ArmExtendedInt_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ArmExtendedInt_SetVector(cyisraddress address) 
{
    CY_SET_REG16(ArmExtendedInt_INTC_VECTOR, (uint16) address);
}


/*******************************************************************************
* Function Name: ArmExtendedInt_GetVector
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
cyisraddress ArmExtendedInt_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(ArmExtendedInt_INTC_VECTOR);
}


/*******************************************************************************
* Function Name: ArmExtendedInt_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ArmExtendedInt_Start
*   or ArmExtendedInt_StartEx will override any effect this method would 
*   have had. This method should only be called after ArmExtendedInt_Start or 
*   ArmExtendedInt_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ArmExtendedInt_SetPriority(uint8 priority) 
{
    *ArmExtendedInt_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: ArmExtendedInt_GetPriority
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
uint8 ArmExtendedInt_GetPriority(void) 
{
    uint8 priority;


    priority = *ArmExtendedInt_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: ArmExtendedInt_Enable
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
void ArmExtendedInt_Enable(void) 
{
    /* Enable the general interrupt. */
    *ArmExtendedInt_INTC_SET_EN = ArmExtendedInt__INTC_MASK;
}


/*******************************************************************************
* Function Name: ArmExtendedInt_GetState
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
uint8 ArmExtendedInt_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return ((*ArmExtendedInt_INTC_SET_EN & (uint8)ArmExtendedInt__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ArmExtendedInt_Disable
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
void ArmExtendedInt_Disable(void) 
{
    /* Disable the general interrupt. */
    *ArmExtendedInt_INTC_CLR_EN = ArmExtendedInt__INTC_MASK;
}


/*******************************************************************************
* Function Name: ArmExtendedInt_SetPending
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
void ArmExtendedInt_SetPending(void) 
{
    *ArmExtendedInt_INTC_SET_PD = ArmExtendedInt__INTC_MASK;
}


/*******************************************************************************
* Function Name: ArmExtendedInt_ClearPending
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
void ArmExtendedInt_ClearPending(void) 
{
    *ArmExtendedInt_INTC_CLR_PD = ArmExtendedInt__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
