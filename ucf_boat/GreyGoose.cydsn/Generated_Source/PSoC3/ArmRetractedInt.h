/*******************************************************************************
* File Name: ArmRetractedInt.h
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

#if !defined(CY_ISR_ArmRetractedInt_H)
#define CY_ISR_ArmRetractedInt_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ArmRetractedInt_Start(void) ;
void ArmRetractedInt_StartEx(cyisraddress address) ;
void ArmRetractedInt_Stop(void) ;

CY_ISR_PROTO(ArmRetractedInt_Interrupt);

void ArmRetractedInt_SetVector(cyisraddress address) ;
cyisraddress ArmRetractedInt_GetVector(void) ;

void ArmRetractedInt_SetPriority(uint8 priority) ;
uint8 ArmRetractedInt_GetPriority(void) ;

void ArmRetractedInt_Enable(void) ;
uint8 ArmRetractedInt_GetState(void) ;
void ArmRetractedInt_Disable(void) ;

void ArmRetractedInt_SetPending(void) ;
void ArmRetractedInt_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ArmRetractedInt ISR. */
#define ArmRetractedInt_INTC_VECTOR            ((reg16 *) ArmRetractedInt__INTC_VECT)

/* Address of the ArmRetractedInt ISR priority. */
#define ArmRetractedInt_INTC_PRIOR             ((reg8 *) ArmRetractedInt__INTC_PRIOR_REG)

/* Priority of the ArmRetractedInt interrupt. */
#define ArmRetractedInt_INTC_PRIOR_NUMBER      ArmRetractedInt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ArmRetractedInt interrupt. */
#define ArmRetractedInt_INTC_SET_EN            ((reg8 *) ArmRetractedInt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ArmRetractedInt interrupt. */
#define ArmRetractedInt_INTC_CLR_EN            ((reg8 *) ArmRetractedInt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ArmRetractedInt interrupt state to pending. */
#define ArmRetractedInt_INTC_SET_PD            ((reg8 *) ArmRetractedInt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ArmRetractedInt interrupt. */
#define ArmRetractedInt_INTC_CLR_PD            ((reg8 *) ArmRetractedInt__INTC_CLR_PD_REG)



#endif /* CY_ISR_ArmRetractedInt_H */


/* [] END OF FILE */
