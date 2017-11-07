/*******************************************************************************
* File Name: ArmRetracted_switch.h  
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

#if !defined(CY_PINS_ArmRetracted_switch_H) /* Pins ArmRetracted_switch_H */
#define CY_PINS_ArmRetracted_switch_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ArmRetracted_switch_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ArmRetracted_switch_Write(uint8 value) ;
void    ArmRetracted_switch_SetDriveMode(uint8 mode) ;
uint8   ArmRetracted_switch_ReadDataReg(void) ;
uint8   ArmRetracted_switch_Read(void) ;
uint8   ArmRetracted_switch_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ArmRetracted_switch_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ArmRetracted_switch_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ArmRetracted_switch_DM_RES_UP          PIN_DM_RES_UP
#define ArmRetracted_switch_DM_RES_DWN         PIN_DM_RES_DWN
#define ArmRetracted_switch_DM_OD_LO           PIN_DM_OD_LO
#define ArmRetracted_switch_DM_OD_HI           PIN_DM_OD_HI
#define ArmRetracted_switch_DM_STRONG          PIN_DM_STRONG
#define ArmRetracted_switch_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ArmRetracted_switch_MASK               ArmRetracted_switch__MASK
#define ArmRetracted_switch_SHIFT              ArmRetracted_switch__SHIFT
#define ArmRetracted_switch_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ArmRetracted_switch_PS                     (* (reg8 *) ArmRetracted_switch__PS)
/* Data Register */
#define ArmRetracted_switch_DR                     (* (reg8 *) ArmRetracted_switch__DR)
/* Port Number */
#define ArmRetracted_switch_PRT_NUM                (* (reg8 *) ArmRetracted_switch__PRT) 
/* Connect to Analog Globals */                                                  
#define ArmRetracted_switch_AG                     (* (reg8 *) ArmRetracted_switch__AG)                       
/* Analog MUX bux enable */
#define ArmRetracted_switch_AMUX                   (* (reg8 *) ArmRetracted_switch__AMUX) 
/* Bidirectional Enable */                                                        
#define ArmRetracted_switch_BIE                    (* (reg8 *) ArmRetracted_switch__BIE)
/* Bit-mask for Aliased Register Access */
#define ArmRetracted_switch_BIT_MASK               (* (reg8 *) ArmRetracted_switch__BIT_MASK)
/* Bypass Enable */
#define ArmRetracted_switch_BYP                    (* (reg8 *) ArmRetracted_switch__BYP)
/* Port wide control signals */                                                   
#define ArmRetracted_switch_CTL                    (* (reg8 *) ArmRetracted_switch__CTL)
/* Drive Modes */
#define ArmRetracted_switch_DM0                    (* (reg8 *) ArmRetracted_switch__DM0) 
#define ArmRetracted_switch_DM1                    (* (reg8 *) ArmRetracted_switch__DM1)
#define ArmRetracted_switch_DM2                    (* (reg8 *) ArmRetracted_switch__DM2) 
/* Input Buffer Disable Override */
#define ArmRetracted_switch_INP_DIS                (* (reg8 *) ArmRetracted_switch__INP_DIS)
/* LCD Common or Segment Drive */
#define ArmRetracted_switch_LCD_COM_SEG            (* (reg8 *) ArmRetracted_switch__LCD_COM_SEG)
/* Enable Segment LCD */
#define ArmRetracted_switch_LCD_EN                 (* (reg8 *) ArmRetracted_switch__LCD_EN)
/* Slew Rate Control */
#define ArmRetracted_switch_SLW                    (* (reg8 *) ArmRetracted_switch__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ArmRetracted_switch_PRTDSI__CAPS_SEL       (* (reg8 *) ArmRetracted_switch__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ArmRetracted_switch_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ArmRetracted_switch__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ArmRetracted_switch_PRTDSI__OE_SEL0        (* (reg8 *) ArmRetracted_switch__PRTDSI__OE_SEL0) 
#define ArmRetracted_switch_PRTDSI__OE_SEL1        (* (reg8 *) ArmRetracted_switch__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ArmRetracted_switch_PRTDSI__OUT_SEL0       (* (reg8 *) ArmRetracted_switch__PRTDSI__OUT_SEL0) 
#define ArmRetracted_switch_PRTDSI__OUT_SEL1       (* (reg8 *) ArmRetracted_switch__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ArmRetracted_switch_PRTDSI__SYNC_OUT       (* (reg8 *) ArmRetracted_switch__PRTDSI__SYNC_OUT) 


#if defined(ArmRetracted_switch__INTSTAT)  /* Interrupt Registers */

    #define ArmRetracted_switch_INTSTAT                (* (reg8 *) ArmRetracted_switch__INTSTAT)
    #define ArmRetracted_switch_SNAP                   (* (reg8 *) ArmRetracted_switch__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ArmRetracted_switch_H */


/* [] END OF FILE */
