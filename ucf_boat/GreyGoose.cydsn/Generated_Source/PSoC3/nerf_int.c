/*******************************************************************************
* File Name: nerf_int.c  
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
#include <nerf_int.H>

#if !defined(nerf_int__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START nerf_int_intc` */
extern void nerf_fire_Write(uint8);
extern void SendNerfStatus(uint8) reentrant;
/* `#END` */


/*******************************************************************************
* Function Name: nerf_int_Start
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
void nerf_int_Start(void) 
{
    /* For all we know the interrupt is active. */
    nerf_int_Disable();

    /* Set the ISR to point to the nerf_int Interrupt. */
    nerf_int_SetVector(&nerf_int_Interrupt);

    /* Set the priority. */
    nerf_int_SetPriority((uint8)nerf_int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    nerf_int_Enable();
}


/*******************************************************************************
* Function Name: nerf_int_StartEx
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
void nerf_int_StartEx(cyisraddress address) 
{
    /* For all we know the interrupt is active. */
    nerf_int_Disable();

    /* Set the ISR to point to the nerf_int Interrupt. */
    nerf_int_SetVector(address);

    /* Set the priority. */
    nerf_int_SetPriority((uint8)nerf_int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    nerf_int_Enable();
}


/*******************************************************************************
* Function Name: nerf_int_Stop
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
void nerf_int_Stop(void) 
{
    /* Disable this interrupt. */
    nerf_int_Disable();
}


/*******************************************************************************
* Function Name: nerf_int_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for nerf_int.
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
CY_ISR(nerf_int_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START nerf_int_Interrupt` */
    nerf_fire_Write(0);
    SendNerfStatus((uint8)'P');
    //UART_1_PutString("hello\n");
    
    //nerf_fired = 0;
    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (nerf_int__ES2_PATCH ))      
            nerf_int_ISR_PATCH();
        #endif /* CYDEV_CHIP_REVISION_USED */
    #endif /* (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */
}


/*******************************************************************************
* Function Name: nerf_int_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling nerf_int_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use nerf_int_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void nerf_int_SetVector(cyisraddress address) 
{
    CY_SET_REG16(nerf_int_INTC_VECTOR, (uint16) address);
}


/*******************************************************************************
* Function Name: nerf_int_GetVector
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
cyisraddress nerf_int_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(nerf_int_INTC_VECTOR);
}


/*******************************************************************************
* Function Name: nerf_int_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling nerf_int_Start
*   or nerf_int_StartEx will override any effect this method would 
*   have had. This method should only be called after nerf_int_Start or 
*   nerf_int_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void nerf_int_SetPriority(uint8 priority) 
{
    *nerf_int_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: nerf_int_GetPriority
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
uint8 nerf_int_GetPriority(void) 
{
    uint8 priority;


    priority = *nerf_int_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: nerf_int_Enable
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
void nerf_int_Enable(void) 
{
    /* Enable the general interrupt. */
    *nerf_int_INTC_SET_EN = nerf_int__INTC_MASK;
}


/*******************************************************************************
* Function Name: nerf_int_GetState
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
uint8 nerf_int_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return ((*nerf_int_INTC_SET_EN & (uint8)nerf_int__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: nerf_int_Disable
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
void nerf_int_Disable(void) 
{
    /* Disable the general interrupt. */
    *nerf_int_INTC_CLR_EN = nerf_int__INTC_MASK;
}


/*******************************************************************************
* Function Name: nerf_int_SetPending
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
void nerf_int_SetPending(void) 
{
    *nerf_int_INTC_SET_PD = nerf_int__INTC_MASK;
}


/*******************************************************************************
* Function Name: nerf_int_ClearPending
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
void nerf_int_ClearPending(void) 
{
    *nerf_int_INTC_CLR_PD = nerf_int__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
