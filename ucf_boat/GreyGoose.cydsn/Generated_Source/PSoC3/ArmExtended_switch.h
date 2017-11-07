/*******************************************************************************
* File Name: ArmExtended_switch.h  
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

#if !defined(CY_PINS_ArmExtended_switch_H) /* Pins ArmExtended_switch_H */
#define CY_PINS_ArmExtended_switch_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ArmExtended_switch_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ArmExtended_switch_Write(uint8 value) ;
void    ArmExtended_switch_SetDriveMode(uint8 mode) ;
uint8   ArmExtended_switch_ReadDataReg(void) ;
uint8   ArmExtended_switch_Read(void) ;
uint8   ArmExtended_switch_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ArmExtended_switch_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ArmExtended_switch_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ArmExtended_switch_DM_RES_UP          PIN_DM_RES_UP
#define ArmExtended_switch_DM_RES_DWN         PIN_DM_RES_DWN
#define ArmExtended_switch_DM_OD_LO           PIN_DM_OD_LO
#define ArmExtended_switch_DM_OD_HI           PIN_DM_OD_HI
#define ArmExtended_switch_DM_STRONG          PIN_DM_STRONG
#define ArmExtended_switch_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ArmExtended_switch_MASK               ArmExtended_switch__MASK
#define ArmExtended_switch_SHIFT              ArmExtended_switch__SHIFT
#define ArmExtended_switch_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ArmExtended_switch_PS                     (* (reg8 *) ArmExtended_switch__PS)
/* Data Register */
#define ArmExtended_switch_DR                     (* (reg8 *) ArmExtended_switch__DR)
/* Port Number */
#define ArmExtended_switch_PRT_NUM                (* (reg8 *) ArmExtended_switch__PRT) 
/* Connect to Analog Globals */                                                  
#define ArmExtended_switch_AG                     (* (reg8 *) ArmExtended_switch__AG)                       
/* Analog MUX bux enable */
#define ArmExtended_switch_AMUX                   (* (reg8 *) ArmExtended_switch__AMUX) 
/* Bidirectional Enable */                                                        
#define ArmExtended_switch_BIE                    (* (reg8 *) ArmExtended_switch__BIE)
/* Bit-mask for Aliased Register Access */
#define ArmExtended_switch_BIT_MASK               (* (reg8 *) ArmExtended_switch__BIT_MASK)
/* Bypass Enable */
#define ArmExtended_switch_BYP                    (* (reg8 *) ArmExtended_switch__BYP)
/* Port wide control signals */                                                   
#define ArmExtended_switch_CTL                    (* (reg8 *) ArmExtended_switch__CTL)
/* Drive Modes */
#define ArmExtended_switch_DM0                    (* (reg8 *) ArmExtended_switch__DM0) 
#define ArmExtended_switch_DM1                    (* (reg8 *) ArmExtended_switch__DM1)
#define ArmExtended_switch_DM2                    (* (reg8 *) ArmExtended_switch__DM2) 
/* Input Buffer Disable Override */
#define ArmExtended_switch_INP_DIS                (* (reg8 *) ArmExtended_switch__INP_DIS)
/* LCD Common or Segment Drive */
#define ArmExtended_switch_LCD_COM_SEG            (* (reg8 *) ArmExtended_switch__LCD_COM_SEG)
/* Enable Segment LCD */
#define ArmExtended_switch_LCD_EN                 (* (reg8 *) ArmExtended_switch__LCD_EN)
/* Slew Rate Control */
#define ArmExtended_switch_SLW                    (* (reg8 *) ArmExtended_switch__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ArmExtended_switch_PRTDSI__CAPS_SEL       (* (reg8 *) ArmExtended_switch__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ArmExtended_switch_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ArmExtended_switch__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ArmExtended_switch_PRTDSI__OE_SEL0        (* (reg8 *) ArmExtended_switch__PRTDSI__OE_SEL0) 
#define ArmExtended_switch_PRTDSI__OE_SEL1        (* (reg8 *) ArmExtended_switch__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ArmExtended_switch_PRTDSI__OUT_SEL0       (* (reg8 *) ArmExtended_switch__PRTDSI__OUT_SEL0) 
#define ArmExtended_switch_PRTDSI__OUT_SEL1       (* (reg8 *) ArmExtended_switch__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ArmExtended_switch_PRTDSI__SYNC_OUT       (* (reg8 *) ArmExtended_switch__PRTDSI__SYNC_OUT) 


#if defined(ArmExtended_switch__INTSTAT)  /* Interrupt Registers */

    #define ArmExtended_switch_INTSTAT                (* (reg8 *) ArmExtended_switch__INTSTAT)
    #define ArmExtended_switch_SNAP                   (* (reg8 *) ArmExtended_switch__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ArmExtended_switch_H */


/* [] END OF FILE */
