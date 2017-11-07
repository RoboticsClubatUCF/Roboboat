/*******************************************************************************
* File Name: isr_RC7.c  
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
#include <isr_RC7.H>


/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_RC7_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: isr_RC7_Start
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
void isr_RC7_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_RC7_Disable();

    /* Set the ISR to point to the isr_RC7 Interrupt. */
    isr_RC7_SetVector(isr_RC7_Interrupt);

    /* Set the priority. */
    isr_RC7_SetPriority(isr_RC7_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_RC7_Enable();
}

/*******************************************************************************
* Function Name: isr_RC7_StartEx
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
void isr_RC7_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_RC7_Disable();

    /* Set the ISR to point to the isr_RC7 Interrupt. */
    isr_RC7_SetVector(address);

    /* Set the priority. */
    isr_RC7_SetPriority(isr_RC7_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_RC7_Enable();
}

/*******************************************************************************
* Function Name: isr_RC7_Stop
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
void isr_RC7_Stop(void) 
{
    /* Disable this interrupt. */
    isr_RC7_Disable();
}

/*******************************************************************************
* Function Name: isr_RC7_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for isr_RC7.
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
CY_ISR(isr_RC7_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_RC7_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (isr_RC7__ES2_PATCH ))      
            isr_RC7_ISR_PATCH();
        #endif
    #endif
}

/*******************************************************************************
* Function Name: isr_RC7_SetVector
********************************************************************************
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_RC7_Start
*   will override any effect this method would have had. To set the vector before
*   the component has been started use isr_RC7_StartEx instead.
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
void isr_RC7_SetVector(cyisraddress address) 
{
    CY_SET_REG16(isr_RC7_INTC_VECTOR, (uint16) address);
}

/*******************************************************************************
* Function Name: isr_RC7_GetVector
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
cyisraddress isr_RC7_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(isr_RC7_INTC_VECTOR);
}

/*******************************************************************************
* Function Name: isr_RC7_SetPriority
********************************************************************************
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_RC7_Start
*   or isr_RC7_StartEx will override any effect this method would have had. 
*	This method should only be called after isr_RC7_Start or 
*	isr_RC7_StartEx has been called. To set the initial
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
void isr_RC7_SetPriority(uint8 priority) 
{
    *isr_RC7_INTC_PRIOR = priority << 5;
}

/*******************************************************************************
* Function Name: isr_RC7_GetPriority
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
uint8 isr_RC7_GetPriority(void) 
{
    uint8 priority;


    priority = *isr_RC7_INTC_PRIOR >> 5;

    return priority;
}

/*******************************************************************************
* Function Name: isr_RC7_Enable
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
void isr_RC7_Enable(void) 
{
    /* Enable the general interrupt. */
    *isr_RC7_INTC_SET_EN = isr_RC7__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_RC7_GetState
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
uint8 isr_RC7_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return (*isr_RC7_INTC_SET_EN & isr_RC7__INTC_MASK) ? 1:0;
}

/*******************************************************************************
* Function Name: isr_RC7_Disable
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
void isr_RC7_Disable(void) 
{
    /* Disable the general interrupt. */
    *isr_RC7_INTC_CLR_EN = isr_RC7__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_RC7_SetPending
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
void isr_RC7_SetPending(void) 
{
    *isr_RC7_INTC_SET_PD = isr_RC7__INTC_MASK;
}

/*******************************************************************************
* Function Name: isr_RC7_ClearPending
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
void isr_RC7_ClearPending(void) 
{
    *isr_RC7_INTC_CLR_PD = isr_RC7__INTC_MASK;
}
