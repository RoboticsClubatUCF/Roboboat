/*******************************************************************************
* File Name: isr_Rx.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ISR_isr_Rx_H)
#define CY_ISR_isr_Rx_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_Rx_Start(void) ;
void isr_Rx_StartEx(cyisraddress address) ;
void isr_Rx_Stop(void) ;

CY_ISR_PROTO(isr_Rx_Interrupt);

void isr_Rx_SetVector(cyisraddress address) ;
cyisraddress isr_Rx_GetVector(void) ;

void isr_Rx_SetPriority(uint8 priority) ;
uint8 isr_Rx_GetPriority(void) ;

void isr_Rx_Enable(void) ;
uint8 isr_Rx_GetState(void) ;
void isr_Rx_Disable(void) ;

void isr_Rx_SetPending(void) ;
void isr_Rx_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_Rx ISR. */
#define isr_Rx_INTC_VECTOR            ((reg16 *) isr_Rx__INTC_VECT)

/* Address of the isr_Rx ISR priority. */
#define isr_Rx_INTC_PRIOR             ((reg8 *) isr_Rx__INTC_PRIOR_REG)

/* Priority of the isr_Rx interrupt. */
#define isr_Rx_INTC_PRIOR_NUMBER      isr_Rx__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_Rx interrupt. */
#define isr_Rx_INTC_SET_EN            ((reg8 *) isr_Rx__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_Rx interrupt. */
#define isr_Rx_INTC_CLR_EN            ((reg8 *) isr_Rx__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_Rx interrupt state to pending. */
#define isr_Rx_INTC_SET_PD            ((reg8 *) isr_Rx__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_Rx interrupt. */
#define isr_Rx_INTC_CLR_PD            ((reg8 *) isr_Rx__INTC_CLR_PD_REG)



#endif /* CY_ISR_isr_Rx_H */


/* [] END OF FILE */
