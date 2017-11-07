/*******************************************************************************
* File Name: Reset_Ref.h  
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

#if !defined(CY_PINS_Reset_Ref_H) /* Pins Reset_Ref_H */
#define CY_PINS_Reset_Ref_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Reset_Ref_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Reset_Ref_Write(uint8 value) ;
void    Reset_Ref_SetDriveMode(uint8 mode) ;
uint8   Reset_Ref_ReadDataReg(void) ;
uint8   Reset_Ref_Read(void) ;
uint8   Reset_Ref_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Reset_Ref_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Reset_Ref_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Reset_Ref_DM_RES_UP          PIN_DM_RES_UP
#define Reset_Ref_DM_RES_DWN         PIN_DM_RES_DWN
#define Reset_Ref_DM_OD_LO           PIN_DM_OD_LO
#define Reset_Ref_DM_OD_HI           PIN_DM_OD_HI
#define Reset_Ref_DM_STRONG          PIN_DM_STRONG
#define Reset_Ref_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Reset_Ref_MASK               Reset_Ref__MASK
#define Reset_Ref_SHIFT              Reset_Ref__SHIFT
#define Reset_Ref_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Reset_Ref_PS                     (* (reg8 *) Reset_Ref__PS)
/* Data Register */
#define Reset_Ref_DR                     (* (reg8 *) Reset_Ref__DR)
/* Port Number */
#define Reset_Ref_PRT_NUM                (* (reg8 *) Reset_Ref__PRT) 
/* Connect to Analog Globals */                                                  
#define Reset_Ref_AG                     (* (reg8 *) Reset_Ref__AG)                       
/* Analog MUX bux enable */
#define Reset_Ref_AMUX                   (* (reg8 *) Reset_Ref__AMUX) 
/* Bidirectional Enable */                                                        
#define Reset_Ref_BIE                    (* (reg8 *) Reset_Ref__BIE)
/* Bit-mask for Aliased Register Access */
#define Reset_Ref_BIT_MASK               (* (reg8 *) Reset_Ref__BIT_MASK)
/* Bypass Enable */
#define Reset_Ref_BYP                    (* (reg8 *) Reset_Ref__BYP)
/* Port wide control signals */                                                   
#define Reset_Ref_CTL                    (* (reg8 *) Reset_Ref__CTL)
/* Drive Modes */
#define Reset_Ref_DM0                    (* (reg8 *) Reset_Ref__DM0) 
#define Reset_Ref_DM1                    (* (reg8 *) Reset_Ref__DM1)
#define Reset_Ref_DM2                    (* (reg8 *) Reset_Ref__DM2) 
/* Input Buffer Disable Override */
#define Reset_Ref_INP_DIS                (* (reg8 *) Reset_Ref__INP_DIS)
/* LCD Common or Segment Drive */
#define Reset_Ref_LCD_COM_SEG            (* (reg8 *) Reset_Ref__LCD_COM_SEG)
/* Enable Segment LCD */
#define Reset_Ref_LCD_EN                 (* (reg8 *) Reset_Ref__LCD_EN)
/* Slew Rate Control */
#define Reset_Ref_SLW                    (* (reg8 *) Reset_Ref__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Reset_Ref_PRTDSI__CAPS_SEL       (* (reg8 *) Reset_Ref__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Reset_Ref_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Reset_Ref__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Reset_Ref_PRTDSI__OE_SEL0        (* (reg8 *) Reset_Ref__PRTDSI__OE_SEL0) 
#define Reset_Ref_PRTDSI__OE_SEL1        (* (reg8 *) Reset_Ref__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Reset_Ref_PRTDSI__OUT_SEL0       (* (reg8 *) Reset_Ref__PRTDSI__OUT_SEL0) 
#define Reset_Ref_PRTDSI__OUT_SEL1       (* (reg8 *) Reset_Ref__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Reset_Ref_PRTDSI__SYNC_OUT       (* (reg8 *) Reset_Ref__PRTDSI__SYNC_OUT) 


#if defined(Reset_Ref__INTSTAT)  /* Interrupt Registers */

    #define Reset_Ref_INTSTAT                (* (reg8 *) Reset_Ref__INTSTAT)
    #define Reset_Ref_SNAP                   (* (reg8 *) Reset_Ref__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Reset_Ref_H */


/* [] END OF FILE */
