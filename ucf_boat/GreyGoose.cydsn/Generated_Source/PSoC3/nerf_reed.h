/*******************************************************************************
* File Name: nerf_reed.h  
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

#if !defined(CY_PINS_nerf_reed_H) /* Pins nerf_reed_H */
#define CY_PINS_nerf_reed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nerf_reed_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    nerf_reed_Write(uint8 value) ;
void    nerf_reed_SetDriveMode(uint8 mode) ;
uint8   nerf_reed_ReadDataReg(void) ;
uint8   nerf_reed_Read(void) ;
uint8   nerf_reed_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define nerf_reed_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define nerf_reed_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define nerf_reed_DM_RES_UP          PIN_DM_RES_UP
#define nerf_reed_DM_RES_DWN         PIN_DM_RES_DWN
#define nerf_reed_DM_OD_LO           PIN_DM_OD_LO
#define nerf_reed_DM_OD_HI           PIN_DM_OD_HI
#define nerf_reed_DM_STRONG          PIN_DM_STRONG
#define nerf_reed_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define nerf_reed_MASK               nerf_reed__MASK
#define nerf_reed_SHIFT              nerf_reed__SHIFT
#define nerf_reed_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nerf_reed_PS                     (* (reg8 *) nerf_reed__PS)
/* Data Register */
#define nerf_reed_DR                     (* (reg8 *) nerf_reed__DR)
/* Port Number */
#define nerf_reed_PRT_NUM                (* (reg8 *) nerf_reed__PRT) 
/* Connect to Analog Globals */                                                  
#define nerf_reed_AG                     (* (reg8 *) nerf_reed__AG)                       
/* Analog MUX bux enable */
#define nerf_reed_AMUX                   (* (reg8 *) nerf_reed__AMUX) 
/* Bidirectional Enable */                                                        
#define nerf_reed_BIE                    (* (reg8 *) nerf_reed__BIE)
/* Bit-mask for Aliased Register Access */
#define nerf_reed_BIT_MASK               (* (reg8 *) nerf_reed__BIT_MASK)
/* Bypass Enable */
#define nerf_reed_BYP                    (* (reg8 *) nerf_reed__BYP)
/* Port wide control signals */                                                   
#define nerf_reed_CTL                    (* (reg8 *) nerf_reed__CTL)
/* Drive Modes */
#define nerf_reed_DM0                    (* (reg8 *) nerf_reed__DM0) 
#define nerf_reed_DM1                    (* (reg8 *) nerf_reed__DM1)
#define nerf_reed_DM2                    (* (reg8 *) nerf_reed__DM2) 
/* Input Buffer Disable Override */
#define nerf_reed_INP_DIS                (* (reg8 *) nerf_reed__INP_DIS)
/* LCD Common or Segment Drive */
#define nerf_reed_LCD_COM_SEG            (* (reg8 *) nerf_reed__LCD_COM_SEG)
/* Enable Segment LCD */
#define nerf_reed_LCD_EN                 (* (reg8 *) nerf_reed__LCD_EN)
/* Slew Rate Control */
#define nerf_reed_SLW                    (* (reg8 *) nerf_reed__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nerf_reed_PRTDSI__CAPS_SEL       (* (reg8 *) nerf_reed__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nerf_reed_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nerf_reed__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nerf_reed_PRTDSI__OE_SEL0        (* (reg8 *) nerf_reed__PRTDSI__OE_SEL0) 
#define nerf_reed_PRTDSI__OE_SEL1        (* (reg8 *) nerf_reed__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nerf_reed_PRTDSI__OUT_SEL0       (* (reg8 *) nerf_reed__PRTDSI__OUT_SEL0) 
#define nerf_reed_PRTDSI__OUT_SEL1       (* (reg8 *) nerf_reed__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nerf_reed_PRTDSI__SYNC_OUT       (* (reg8 *) nerf_reed__PRTDSI__SYNC_OUT) 


#if defined(nerf_reed__INTSTAT)  /* Interrupt Registers */

    #define nerf_reed_INTSTAT                (* (reg8 *) nerf_reed__INTSTAT)
    #define nerf_reed_SNAP                   (* (reg8 *) nerf_reed__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins nerf_reed_H */


/* [] END OF FILE */
