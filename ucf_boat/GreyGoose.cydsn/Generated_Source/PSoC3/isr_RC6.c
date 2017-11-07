/*******************************************************************************
* File Name: isr_RC6.c  
* Version 1.50
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include <CYDEVICE.H>
#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <isr_RC6.H>


/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_RC6_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: isr_RC6_Start
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   void.
*
*
* Return:
*   void.
*
*******************************************************************************/
void isr_RC6_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_RC6_Disable();

    /* Set the ISR to point to the isr_RC6 Interrupt. */
    isr_RC6_SetVector(isr_RC6_Interrupt);

    /* Set the priority. */
    isr_RC6_SetPriority(isr_RC6_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_RC6_Enable();
}

/*******************************************************************************
* Function Name: isr_RC6_StartEx
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*******************************************************************************/
void isr_RC6_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_RC6_Disable();

    /* Set the ISR to point to the isr_RC6 Interrupt. */
    isr_RC6_SetVector(address);

    /* Set the priority. */
    isr_RC6_SetPriority(isr_RC6_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_RC6_Enable();
}

/*******************************************************************************
* Function Name: isr_RC6_Stop
********************************************************************************
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
void isr_RC6_Stop(void) 
{
    /* Disable this interrupt. */
    isr_RC6_Disable();
}

/*******************************************************************************
* Function Name: isr_RC6_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for isr_RC6.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
*
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
CY_ISR(isr_RC6_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_RC6_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (isr_RC6__ES2_PATCH ))      
            isr_RC6_ISR_PATCH();
        #endif
    #endif
}

/*******************************************************************************
* Function Name: isr_RC6_SetVector
********************************************************************************
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_RC6_Start
*   will override any effect this method would have had. To set the vector before
*   the component has been started use isr_RC6_StartEx instead.
*
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void isr_RC6_SetVector(cyisraddress address) 
{
    CY_SET_REG16(isr_RC6_INTC_VECTOR, (uint16) address);
}

/*******************************************************************************
* Function Name: isr_RC6_GetVector
********************************************************************************
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*
*******************************************************************************/
cyisraddress isr_RC6_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(isr_RC6_INTC_VECTOR);
}

/*******************************************************************************
* Function Name: isr_RC6_SetPriority
********************************************************************************
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_RC6_Start
*   or isr_RC6_StartEx will override any effect this method would have had. 
*	This method should only be called after isr_RC6_Start or 
*	isr_RC6_StartEx has been called. To set the initial
*	priority for the component use the cydwr file in the tool.
*
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void isr_RC6_SetPriority(uint8 priority) 
{
    *isr_RC6_INTC_PRIOR = priority << 5;
}

/*******************************************************************************
* Function Name: isr_RC6_GetPriority
********************************************************************************
* Summary:
*   Gets the Priority of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
*******************************************************************************/
uint8 isr_RC6_GetPriority(void) 
{
    uint8 priority;


    priority = *isr_RC6_INTC_PRIOR >> 5;

    return priority;
}

/*******************************************************************************
* Function Name: isr_RC6_Enable
********************************************************************************
* Summary:
*   Enables the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void isr_RC6_Enable(void) 
{
    /* Enable the general interrupt. */
    *isr_RC6_INTC_SET_EN = isr_RC6__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_RC6_GetState
********************************************************************************
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   1 if enabled, 0 if disabled.
*
*
*******************************************************************************/
uint8 isr_RC6_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return (*isr_RC6_INTC_SET_EN & isr_RC6__INTC_MASK) ? 1:0;
}

/*******************************************************************************
* Function Name: isr_RC6_Disable
********************************************************************************
* Summary:
*   Disables the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void isr_RC6_Disable(void) 
{
    /* Disable the general interrupt. */
    *isr_RC6_INTC_CLR_EN = isr_RC6__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_RC6_SetPending
********************************************************************************
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void isr_RC6_SetPending(void) 
{
    *isr_RC6_INTC_SET_PD = isr_RC6__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_RC6_ClearPending
********************************************************************************
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void isr_RC6_ClearPending(void) 
{
    *isr_RC6_INTC_CLR_PD = isr_RC6__INTC_MASK;
}
