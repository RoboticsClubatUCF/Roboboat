/*******************************************************************************
* File Name: Rx_RBTQ2.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Rx_RBTQ2_H) /* Pins Rx_RBTQ2_H */
#define CY_PINS_Rx_RBTQ2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rx_RBTQ2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Rx_RBTQ2_Write(uint8 value) ;
void    Rx_RBTQ2_SetDriveMode(uint8 mode) ;
uint8   Rx_RBTQ2_ReadDataReg(void) ;
uint8   Rx_RBTQ2_Read(void) ;
uint8   Rx_RBTQ2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Rx_RBTQ2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Rx_RBTQ2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Rx_RBTQ2_DM_RES_UP          PIN_DM_RES_UP
#define Rx_RBTQ2_DM_RES_DWN         PIN_DM_RES_DWN
#define Rx_RBTQ2_DM_OD_LO           PIN_DM_OD_LO
#define Rx_RBTQ2_DM_OD_HI           PIN_DM_OD_HI
#define Rx_RBTQ2_DM_STRONG          PIN_DM_STRONG
#define Rx_RBTQ2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Rx_RBTQ2_MASK               Rx_RBTQ2__MASK
#define Rx_RBTQ2_SHIFT              Rx_RBTQ2__SHIFT
#define Rx_RBTQ2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rx_RBTQ2_PS                     (* (reg8 *) Rx_RBTQ2__PS)
/* Data Register */
#define Rx_RBTQ2_DR                     (* (reg8 *) Rx_RBTQ2__DR)
/* Port Number */
#define Rx_RBTQ2_PRT_NUM                (* (reg8 *) Rx_RBTQ2__PRT) 
/* Connect to Analog Globals */                                                  
#define Rx_RBTQ2_AG                     (* (reg8 *) Rx_RBTQ2__AG)                       
/* Analog MUX bux enable */
#define Rx_RBTQ2_AMUX                   (* (reg8 *) Rx_RBTQ2__AMUX) 
/* Bidirectional Enable */                                                        
#define Rx_RBTQ2_BIE                    (* (reg8 *) Rx_RBTQ2__BIE)
/* Bit-mask for Aliased Register Access */
#define Rx_RBTQ2_BIT_MASK               (* (reg8 *) Rx_RBTQ2__BIT_MASK)
/* Bypass Enable */
#define Rx_RBTQ2_BYP                    (* (reg8 *) Rx_RBTQ2__BYP)
/* Port wide control signals */                                                   
#define Rx_RBTQ2_CTL                    (* (reg8 *) Rx_RBTQ2__CTL)
/* Drive Modes */
#define Rx_RBTQ2_DM0                    (* (reg8 *) Rx_RBTQ2__DM0) 
#define Rx_RBTQ2_DM1                    (* (reg8 *) Rx_RBTQ2__DM1)
#define Rx_RBTQ2_DM2                    (* (reg8 *) Rx_RBTQ2__DM2) 
/* Input Buffer Disable Override */
#define Rx_RBTQ2_INP_DIS                (* (reg8 *) Rx_RBTQ2__INP_DIS)
/* LCD Common or Segment Drive */
#define Rx_RBTQ2_LCD_COM_SEG            (* (reg8 *) Rx_RBTQ2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rx_RBTQ2_LCD_EN                 (* (reg8 *) Rx_RBTQ2__LCD_EN)
/* Slew Rate Control */
#define Rx_RBTQ2_SLW                    (* (reg8 *) Rx_RBTQ2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rx_RBTQ2_PRTDSI__CAPS_SEL       (* (reg8 *) Rx_RBTQ2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rx_RBTQ2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rx_RBTQ2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rx_RBTQ2_PRTDSI__OE_SEL0        (* (reg8 *) Rx_RBTQ2__PRTDSI__OE_SEL0) 
#define Rx_RBTQ2_PRTDSI__OE_SEL1        (* (reg8 *) Rx_RBTQ2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rx_RBTQ2_PRTDSI__OUT_SEL0       (* (reg8 *) Rx_RBTQ2__PRTDSI__OUT_SEL0) 
#define Rx_RBTQ2_PRTDSI__OUT_SEL1       (* (reg8 *) Rx_RBTQ2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rx_RBTQ2_PRTDSI__SYNC_OUT       (* (reg8 *) Rx_RBTQ2__PRTDSI__SYNC_OUT) 


#if defined(Rx_RBTQ2__INTSTAT)  /* Interrupt Registers */

    #define Rx_RBTQ2_INTSTAT                (* (reg8 *) Rx_RBTQ2__INTSTAT)
    #define Rx_RBTQ2_SNAP                   (* (reg8 *) Rx_RBTQ2__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Rx_RBTQ2_H */


/* [] END OF FILE */
