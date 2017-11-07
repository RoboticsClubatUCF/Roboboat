/*******************************************************************************
* File Name: isr_RC3.h
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
#if !defined(__isr_RC3_INTC_H__)
#define __isr_RC3_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define isr_RC3_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif


/* Interrupt Controller API. */
void isr_RC3_Start(void);
void isr_RC3_StartEx(cyisraddress address);
void isr_RC3_Stop(void) ;

CY_ISR_PROTO(isr_RC3_Interrupt);

void isr_RC3_SetVector(cyisraddress address) ;
cyisraddress isr_RC3_GetVector(void) ;

void isr_RC3_SetPriority(uint8 priority) ;
uint8 isr_RC3_GetPriority(void) ;

void isr_RC3_Enable(void) ;
uint8 isr_RC3_GetState(void) ;
void isr_RC3_Disable(void) ;

void isr_RC3_SetPending(void) ;
void isr_RC3_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_RC3 ISR. */
#define isr_RC3_INTC_VECTOR            ((reg16 *) isr_RC3__INTC_VECT)

/* Address of the isr_RC3 ISR priority. */
#define isr_RC3_INTC_PRIOR             ((reg8 *) isr_RC3__INTC_PRIOR_REG)

/* Priority of the isr_RC3 interrupt. */
#define isr_RC3_INTC_PRIOR_NUMBER      isr_RC3__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_RC3 interrupt. */
#define isr_RC3_INTC_SET_EN            ((reg8 *) isr_RC3__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_RC3 interrupt. */
#define isr_RC3_INTC_CLR_EN            ((reg8 *) isr_RC3__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_RC3 interrupt state to pending. */
#define isr_RC3_INTC_SET_PD            ((reg8 *) isr_RC3__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_RC3 interrupt. */
#define isr_RC3_INTC_CLR_PD            ((reg8 *) isr_RC3__INTC_CLR_PD_REG)



/* __isr_RC3_INTC_H__ */
#endif
