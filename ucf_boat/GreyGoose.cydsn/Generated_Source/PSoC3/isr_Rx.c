/*******************************************************************************
* File Name: isr_Rx.c  
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
#include <isr_Rx.H>

#if !defined(isr_Rx__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_Rx_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: isr_Rx_Start
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
void isr_Rx_Start(void) 
{
    /* For all we know the interrupt is active. */
    isr_Rx_Disable();

    /* Set the ISR to point to the isr_Rx Interrupt. */
    isr_Rx_SetVector(&isr_Rx_Interrupt);

    /* Set the priority. */
    isr_Rx_SetPriority((uint8)isr_Rx_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_Rx_Enable();
}


/*******************************************************************************
* Function Name: isr_Rx_StartEx
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
void isr_Rx_StartEx(cyisraddress address) 
{
    /* For all we know the interrupt is active. */
    isr_Rx_Disable();

    /* Set the ISR to point to the isr_Rx Interrupt. */
    isr_Rx_SetVector(address);

    /* Set the priority. */
    isr_Rx_SetPriority((uint8)isr_Rx_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_Rx_Enable();
}


/*******************************************************************************
* Function Name: isr_Rx_Stop
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
void isr_Rx_Stop(void) 
{
    /* Disable this interrupt. */
    isr_Rx_Disable();
}


/*******************************************************************************
* Function Name: isr_Rx_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for isr_Rx.
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
CY_ISR(isr_Rx_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_Rx_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (isr_Rx__ES2_PATCH ))      
            isr_Rx_ISR_PATCH();
        #endif /* CYDEV_CHIP_REVISION_USED */
    #endif /* (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */
}


/*******************************************************************************
* Function Name: isr_Rx_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_Rx_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_Rx_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_Rx_SetVector(cyisraddress address) 
{
    CY_SET_REG16(isr_Rx_INTC_VECTOR, (uint16) address);
}


/*******************************************************************************
* Function Name: isr_Rx_GetVector
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
cyisraddress isr_Rx_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(isr_Rx_INTC_VECTOR);
}


/*******************************************************************************
* Function Name: isr_Rx_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_Rx_Start
*   or isr_Rx_StartEx will override any effect this method would 
*   have had. This method should only be called after isr_Rx_Start or 
*   isr_Rx_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_Rx_SetPriority(uint8 priority) 
{
    *isr_Rx_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_Rx_GetPriority
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
uint8 isr_Rx_GetPriority(void) 
{
    uint8 priority;


    priority = *isr_Rx_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_Rx_Enable
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
void isr_Rx_Enable(void) 
{
    /* Enable the general interrupt. */
    *isr_Rx_INTC_SET_EN = isr_Rx__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_Rx_GetState
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
uint8 isr_Rx_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return ((*isr_Rx_INTC_SET_EN & (uint8)isr_Rx__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_Rx_Disable
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
void isr_Rx_Disable(void) 
{
    /* Disable the general interrupt. */
    *isr_Rx_INTC_CLR_EN = isr_Rx__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_Rx_SetPending
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
void isr_Rx_SetPending(void) 
{
    *isr_Rx_INTC_SET_PD = isr_Rx__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_Rx_ClearPending
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
void isr_Rx_ClearPending(void) 
{
    *isr_Rx_INTC_CLR_PD = isr_Rx__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
