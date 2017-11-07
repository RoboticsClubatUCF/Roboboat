/*******************************************************************************
* File Name: isr_RC3P.h
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

#if !defined(CY_ISR_isr_RC3P_H)
#define CY_ISR_isr_RC3P_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_RC3P_Start(void) ;
void isr_RC3P_StartEx(cyisraddress address) ;
void isr_RC3P_Stop(void) ;

CY_ISR_PROTO(isr_RC3P_Interrupt);

void isr_RC3P_SetVector(cyisraddress address) ;
cyisraddress isr_RC3P_GetVector(void) ;

void isr_RC3P_SetPriority(uint8 priority) ;
uint8 isr_RC3P_GetPriority(void) ;

void isr_RC3P_Enable(void) ;
uint8 isr_RC3P_GetState(void) ;
void isr_RC3P_Disable(void) ;

void isr_RC3P_SetPending(void) ;
void isr_RC3P_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_RC3P ISR. */
#define isr_RC3P_INTC_VECTOR            ((reg16 *) isr_RC3P__INTC_VECT)

/* Address of the isr_RC3P ISR priority. */
#define isr_RC3P_INTC_PRIOR             ((reg8 *) isr_RC3P__INTC_PRIOR_REG)

/* Priority of the isr_RC3P interrupt. */
#define isr_RC3P_INTC_PRIOR_NUMBER      isr_RC3P__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_RC3P interrupt. */
#define isr_RC3P_INTC_SET_EN            ((reg8 *) isr_RC3P__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_RC3P interrupt. */
#define isr_RC3P_INTC_CLR_EN            ((reg8 *) isr_RC3P__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_RC3P interrupt state to pending. */
#define isr_RC3P_INTC_SET_PD            ((reg8 *) isr_RC3P__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_RC3P interrupt. */
#define isr_RC3P_INTC_CLR_PD            ((reg8 *) isr_RC3P__INTC_CLR_PD_REG)



#endif /* CY_ISR_isr_RC3P_H */


/* [] END OF FILE */
