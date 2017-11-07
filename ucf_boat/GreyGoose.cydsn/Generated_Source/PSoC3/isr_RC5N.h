/*******************************************************************************
* File Name: isr_RC5N.h
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

#if !defined(CY_ISR_isr_RC5N_H)
#define CY_ISR_isr_RC5N_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_RC5N_Start(void) ;
void isr_RC5N_StartEx(cyisraddress address) ;
void isr_RC5N_Stop(void) ;

CY_ISR_PROTO(isr_RC5N_Interrupt);

void isr_RC5N_SetVector(cyisraddress address) ;
cyisraddress isr_RC5N_GetVector(void) ;

void isr_RC5N_SetPriority(uint8 priority) ;
uint8 isr_RC5N_GetPriority(void) ;

void isr_RC5N_Enable(void) ;
uint8 isr_RC5N_GetState(void) ;
void isr_RC5N_Disable(void) ;

void isr_RC5N_SetPending(void) ;
void isr_RC5N_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_RC5N ISR. */
#define isr_RC5N_INTC_VECTOR            ((reg16 *) isr_RC5N__INTC_VECT)

/* Address of the isr_RC5N ISR priority. */
#define isr_RC5N_INTC_PRIOR             ((reg8 *) isr_RC5N__INTC_PRIOR_REG)

/* Priority of the isr_RC5N interrupt. */
#define isr_RC5N_INTC_PRIOR_NUMBER      isr_RC5N__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_RC5N interrupt. */
#define isr_RC5N_INTC_SET_EN            ((reg8 *) isr_RC5N__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_RC5N interrupt. */
#define isr_RC5N_INTC_CLR_EN            ((reg8 *) isr_RC5N__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_RC5N interrupt state to pending. */
#define isr_RC5N_INTC_SET_PD            ((reg8 *) isr_RC5N__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_RC5N interrupt. */
#define isr_RC5N_INTC_CLR_PD            ((reg8 *) isr_RC5N__INTC_CLR_PD_REG)



#endif /* CY_ISR_isr_RC5N_H */


/* [] END OF FILE */
