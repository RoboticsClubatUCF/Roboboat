/*******************************************************************************
* File Name: nerf_int.h
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

#if !defined(CY_ISR_nerf_int_H)
#define CY_ISR_nerf_int_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void nerf_int_Start(void) ;
void nerf_int_StartEx(cyisraddress address) ;
void nerf_int_Stop(void) ;

CY_ISR_PROTO(nerf_int_Interrupt);

void nerf_int_SetVector(cyisraddress address) ;
cyisraddress nerf_int_GetVector(void) ;

void nerf_int_SetPriority(uint8 priority) ;
uint8 nerf_int_GetPriority(void) ;

void nerf_int_Enable(void) ;
uint8 nerf_int_GetState(void) ;
void nerf_int_Disable(void) ;

void nerf_int_SetPending(void) ;
void nerf_int_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the nerf_int ISR. */
#define nerf_int_INTC_VECTOR            ((reg16 *) nerf_int__INTC_VECT)

/* Address of the nerf_int ISR priority. */
#define nerf_int_INTC_PRIOR             ((reg8 *) nerf_int__INTC_PRIOR_REG)

/* Priority of the nerf_int interrupt. */
#define nerf_int_INTC_PRIOR_NUMBER      nerf_int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable nerf_int interrupt. */
#define nerf_int_INTC_SET_EN            ((reg8 *) nerf_int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the nerf_int interrupt. */
#define nerf_int_INTC_CLR_EN            ((reg8 *) nerf_int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the nerf_int interrupt state to pending. */
#define nerf_int_INTC_SET_PD            ((reg8 *) nerf_int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the nerf_int interrupt. */
#define nerf_int_INTC_CLR_PD            ((reg8 *) nerf_int__INTC_CLR_PD_REG)



#endif /* CY_ISR_nerf_int_H */


/* [] END OF FILE */
