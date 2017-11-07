/*******************************************************************************
* File Name: isr_RC5.h
* Version 1.50
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(__isr_RC5_INTC_H__)
#define __isr_RC5_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define isr_RC5_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif


/* Interrupt Controller API. */
void isr_RC5_Start(void);
void isr_RC5_StartEx(cyisraddress address);
void isr_RC5_Stop(void) ;

CY_ISR_PROTO(isr_RC5_Interrupt);

void isr_RC5_SetVector(cyisraddress address) ;
cyisraddress isr_RC5_GetVector(void) ;

void isr_RC5_SetPriority(uint8 priority) ;
uint8 isr_RC5_GetPriority(void) ;

void isr_RC5_Enable(void) ;
uint8 isr_RC5_GetState(void) ;
void isr_RC5_Disable(void) ;

void isr_RC5_SetPending(void) ;
void isr_RC5_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_RC5 ISR. */
#define isr_RC5_INTC_VECTOR            ((reg16 *) isr_RC5__INTC_VECT)

/* Address of the isr_RC5 ISR priority. */
#define isr_RC5_INTC_PRIOR             ((reg8 *) isr_RC5__INTC_PRIOR_REG)

/* Priority of the isr_RC5 interrupt. */
#define isr_RC5_INTC_PRIOR_NUMBER      isr_RC5__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_RC5 interrupt. */
#define isr_RC5_INTC_SET_EN            ((reg8 *) isr_RC5__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_RC5 interrupt. */
#define isr_RC5_INTC_CLR_EN            ((reg8 *) isr_RC5__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_RC5 interrupt state to pending. */
#define isr_RC5_INTC_SET_PD            ((reg8 *) isr_RC5__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_RC5 interrupt. */
#define isr_RC5_INTC_CLR_PD            ((reg8 *) isr_RC5__INTC_CLR_PD_REG)



/* __isr_RC5_INTC_H__ */
#endif
