/*******************************************************************************
* File Name: nerf_fire.h  
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

#if !defined(CY_PINS_nerf_fire_H) /* Pins nerf_fire_H */
#define CY_PINS_nerf_fire_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nerf_fire_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    nerf_fire_Write(uint8 value) ;
void    nerf_fire_SetDriveMode(uint8 mode) ;
uint8   nerf_fire_ReadDataReg(void) ;
uint8   nerf_fire_Read(void) ;
uint8   nerf_fire_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define nerf_fire_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define nerf_fire_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define nerf_fire_DM_RES_UP          PIN_DM_RES_UP
#define nerf_fire_DM_RES_DWN         PIN_DM_RES_DWN
#define nerf_fire_DM_OD_LO           PIN_DM_OD_LO
#define nerf_fire_DM_OD_HI           PIN_DM_OD_HI
#define nerf_fire_DM_STRONG          PIN_DM_STRONG
#define nerf_fire_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define nerf_fire_MASK               nerf_fire__MASK
#define nerf_fire_SHIFT              nerf_fire__SHIFT
#define nerf_fire_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nerf_fire_PS                     (* (reg8 *) nerf_fire__PS)
/* Data Register */
#define nerf_fire_DR                     (* (reg8 *) nerf_fire__DR)
/* Port Number */
#define nerf_fire_PRT_NUM                (* (reg8 *) nerf_fire__PRT) 
/* Connect to Analog Globals */                                                  
#define nerf_fire_AG                     (* (reg8 *) nerf_fire__AG)                       
/* Analog MUX bux enable */
#define nerf_fire_AMUX                   (* (reg8 *) nerf_fire__AMUX) 
/* Bidirectional Enable */                                                        
#define nerf_fire_BIE                    (* (reg8 *) nerf_fire__BIE)
/* Bit-mask for Aliased Register Access */
#define nerf_fire_BIT_MASK               (* (reg8 *) nerf_fire__BIT_MASK)
/* Bypass Enable */
#define nerf_fire_BYP                    (* (reg8 *) nerf_fire__BYP)
/* Port wide control signals */                                                   
#define nerf_fire_CTL                    (* (reg8 *) nerf_fire__CTL)
/* Drive Modes */
#define nerf_fire_DM0                    (* (reg8 *) nerf_fire__DM0) 
#define nerf_fire_DM1                    (* (reg8 *) nerf_fire__DM1)
#define nerf_fire_DM2                    (* (reg8 *) nerf_fire__DM2) 
/* Input Buffer Disable Override */
#define nerf_fire_INP_DIS                (* (reg8 *) nerf_fire__INP_DIS)
/* LCD Common or Segment Drive */
#define nerf_fire_LCD_COM_SEG            (* (reg8 *) nerf_fire__LCD_COM_SEG)
/* Enable Segment LCD */
#define nerf_fire_LCD_EN                 (* (reg8 *) nerf_fire__LCD_EN)
/* Slew Rate Control */
#define nerf_fire_SLW                    (* (reg8 *) nerf_fire__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nerf_fire_PRTDSI__CAPS_SEL       (* (reg8 *) nerf_fire__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nerf_fire_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nerf_fire__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nerf_fire_PRTDSI__OE_SEL0        (* (reg8 *) nerf_fire__PRTDSI__OE_SEL0) 
#define nerf_fire_PRTDSI__OE_SEL1        (* (reg8 *) nerf_fire__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nerf_fire_PRTDSI__OUT_SEL0       (* (reg8 *) nerf_fire__PRTDSI__OUT_SEL0) 
#define nerf_fire_PRTDSI__OUT_SEL1       (* (reg8 *) nerf_fire__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nerf_fire_PRTDSI__SYNC_OUT       (* (reg8 *) nerf_fire__PRTDSI__SYNC_OUT) 


#if defined(nerf_fire__INTSTAT)  /* Interrupt Registers */

    #define nerf_fire_INTSTAT                (* (reg8 *) nerf_fire__INTSTAT)
    #define nerf_fire_SNAP                   (* (reg8 *) nerf_fire__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins nerf_fire_H */


/* [] END OF FILE */
