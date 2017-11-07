/*******************************************************************************
* File Name: external.h  
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

#if !defined(CY_PINS_external_H) /* Pins external_H */
#define CY_PINS_external_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "external_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    external_Write(uint8 value) ;
void    external_SetDriveMode(uint8 mode) ;
uint8   external_ReadDataReg(void) ;
uint8   external_Read(void) ;
uint8   external_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define external_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define external_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define external_DM_RES_UP          PIN_DM_RES_UP
#define external_DM_RES_DWN         PIN_DM_RES_DWN
#define external_DM_OD_LO           PIN_DM_OD_LO
#define external_DM_OD_HI           PIN_DM_OD_HI
#define external_DM_STRONG          PIN_DM_STRONG
#define external_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define external_MASK               external__MASK
#define external_SHIFT              external__SHIFT
#define external_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define external_PS                     (* (reg8 *) external__PS)
/* Data Register */
#define external_DR                     (* (reg8 *) external__DR)
/* Port Number */
#define external_PRT_NUM                (* (reg8 *) external__PRT) 
/* Connect to Analog Globals */                                                  
#define external_AG                     (* (reg8 *) external__AG)                       
/* Analog MUX bux enable */
#define external_AMUX                   (* (reg8 *) external__AMUX) 
/* Bidirectional Enable */                                                        
#define external_BIE                    (* (reg8 *) external__BIE)
/* Bit-mask for Aliased Register Access */
#define external_BIT_MASK               (* (reg8 *) external__BIT_MASK)
/* Bypass Enable */
#define external_BYP                    (* (reg8 *) external__BYP)
/* Port wide control signals */                                                   
#define external_CTL                    (* (reg8 *) external__CTL)
/* Drive Modes */
#define external_DM0                    (* (reg8 *) external__DM0) 
#define external_DM1                    (* (reg8 *) external__DM1)
#define external_DM2                    (* (reg8 *) external__DM2) 
/* Input Buffer Disable Override */
#define external_INP_DIS                (* (reg8 *) external__INP_DIS)
/* LCD Common or Segment Drive */
#define external_LCD_COM_SEG            (* (reg8 *) external__LCD_COM_SEG)
/* Enable Segment LCD */
#define external_LCD_EN                 (* (reg8 *) external__LCD_EN)
/* Slew Rate Control */
#define external_SLW                    (* (reg8 *) external__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define external_PRTDSI__CAPS_SEL       (* (reg8 *) external__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define external_PRTDSI__DBL_SYNC_IN    (* (reg8 *) external__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define external_PRTDSI__OE_SEL0        (* (reg8 *) external__PRTDSI__OE_SEL0) 
#define external_PRTDSI__OE_SEL1        (* (reg8 *) external__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define external_PRTDSI__OUT_SEL0       (* (reg8 *) external__PRTDSI__OUT_SEL0) 
#define external_PRTDSI__OUT_SEL1       (* (reg8 *) external__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define external_PRTDSI__SYNC_OUT       (* (reg8 *) external__PRTDSI__SYNC_OUT) 


#if defined(external__INTSTAT)  /* Interrupt Registers */

    #define external_INTSTAT                (* (reg8 *) external__INTSTAT)
    #define external_SNAP                   (* (reg8 *) external__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins external_H */


/* [] END OF FILE */
