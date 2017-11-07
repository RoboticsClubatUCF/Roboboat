/*******************************************************************************
* File Name: ArmExtendedInt.h
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

#if !defined(CY_ISR_ArmExtendedInt_H)
#define CY_ISR_ArmExtendedInt_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ArmExtendedInt_Start(void) ;
void ArmExtendedInt_StartEx(cyisraddress address) ;
void ArmExtendedInt_Stop(void) ;

CY_ISR_PROTO(ArmExtendedInt_Interrupt);

void ArmExtendedInt_SetVector(cyisraddress address) ;
cyisraddress ArmExtendedInt_GetVector(void) ;

void ArmExtendedInt_SetPriority(uint8 priority) ;
uint8 ArmExtendedInt_GetPriority(void) ;

void ArmExtendedInt_Enable(void) ;
uint8 ArmExtendedInt_GetState(void) ;
void ArmExtendedInt_Disable(void) ;

void ArmExtendedInt_SetPending(void) ;
void ArmExtendedInt_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ArmExtendedInt ISR. */
#define ArmExtendedInt_INTC_VECTOR            ((reg16 *) ArmExtendedInt__INTC_VECT)

/* Address of the ArmExtendedInt ISR priority. */
#define ArmExtendedInt_INTC_PRIOR             ((reg8 *) ArmExtendedInt__INTC_PRIOR_REG)

/* Priority of the ArmExtendedInt interrupt. */
#define ArmExtendedInt_INTC_PRIOR_NUMBER      ArmExtendedInt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ArmExtendedInt interrupt. */
#define ArmExtendedInt_INTC_SET_EN            ((reg8 *) ArmExtendedInt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ArmExtendedInt interrupt. */
#define ArmExtendedInt_INTC_CLR_EN            ((reg8 *) ArmExtendedInt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ArmExtendedInt interrupt state to pending. */
#define ArmExtendedInt_INTC_SET_PD            ((reg8 *) ArmExtendedInt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ArmExtendedInt interrupt. */
#define ArmExtendedInt_INTC_CLR_PD            ((reg8 *) ArmExtendedInt__INTC_CLR_PD_REG)



#endif /* CY_ISR_ArmExtendedInt_H */


/* [] END OF FILE */
