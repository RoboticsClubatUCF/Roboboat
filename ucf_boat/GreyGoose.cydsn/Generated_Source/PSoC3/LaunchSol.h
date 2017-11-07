/*******************************************************************************
* File Name: LaunchSol.h  
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

#if !defined(CY_PINS_LaunchSol_H) /* Pins LaunchSol_H */
#define CY_PINS_LaunchSol_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LaunchSol_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LaunchSol_Write(uint8 value) ;
void    LaunchSol_SetDriveMode(uint8 mode) ;
uint8   LaunchSol_ReadDataReg(void) ;
uint8   LaunchSol_Read(void) ;
uint8   LaunchSol_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LaunchSol_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LaunchSol_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LaunchSol_DM_RES_UP          PIN_DM_RES_UP
#define LaunchSol_DM_RES_DWN         PIN_DM_RES_DWN
#define LaunchSol_DM_OD_LO           PIN_DM_OD_LO
#define LaunchSol_DM_OD_HI           PIN_DM_OD_HI
#define LaunchSol_DM_STRONG          PIN_DM_STRONG
#define LaunchSol_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LaunchSol_MASK               LaunchSol__MASK
#define LaunchSol_SHIFT              LaunchSol__SHIFT
#define LaunchSol_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LaunchSol_PS                     (* (reg8 *) LaunchSol__PS)
/* Data Register */
#define LaunchSol_DR                     (* (reg8 *) LaunchSol__DR)
/* Port Number */
#define LaunchSol_PRT_NUM                (* (reg8 *) LaunchSol__PRT) 
/* Connect to Analog Globals */                                                  
#define LaunchSol_AG                     (* (reg8 *) LaunchSol__AG)                       
/* Analog MUX bux enable */
#define LaunchSol_AMUX                   (* (reg8 *) LaunchSol__AMUX) 
/* Bidirectional Enable */                                                        
#define LaunchSol_BIE                    (* (reg8 *) LaunchSol__BIE)
/* Bit-mask for Aliased Register Access */
#define LaunchSol_BIT_MASK               (* (reg8 *) LaunchSol__BIT_MASK)
/* Bypass Enable */
#define LaunchSol_BYP                    (* (reg8 *) LaunchSol__BYP)
/* Port wide control signals */                                                   
#define LaunchSol_CTL                    (* (reg8 *) LaunchSol__CTL)
/* Drive Modes */
#define LaunchSol_DM0                    (* (reg8 *) LaunchSol__DM0) 
#define LaunchSol_DM1                    (* (reg8 *) LaunchSol__DM1)
#define LaunchSol_DM2                    (* (reg8 *) LaunchSol__DM2) 
/* Input Buffer Disable Override */
#define LaunchSol_INP_DIS                (* (reg8 *) LaunchSol__INP_DIS)
/* LCD Common or Segment Drive */
#define LaunchSol_LCD_COM_SEG            (* (reg8 *) LaunchSol__LCD_COM_SEG)
/* Enable Segment LCD */
#define LaunchSol_LCD_EN                 (* (reg8 *) LaunchSol__LCD_EN)
/* Slew Rate Control */
#define LaunchSol_SLW                    (* (reg8 *) LaunchSol__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LaunchSol_PRTDSI__CAPS_SEL       (* (reg8 *) LaunchSol__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LaunchSol_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LaunchSol__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LaunchSol_PRTDSI__OE_SEL0        (* (reg8 *) LaunchSol__PRTDSI__OE_SEL0) 
#define LaunchSol_PRTDSI__OE_SEL1        (* (reg8 *) LaunchSol__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LaunchSol_PRTDSI__OUT_SEL0       (* (reg8 *) LaunchSol__PRTDSI__OUT_SEL0) 
#define LaunchSol_PRTDSI__OUT_SEL1       (* (reg8 *) LaunchSol__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LaunchSol_PRTDSI__SYNC_OUT       (* (reg8 *) LaunchSol__PRTDSI__SYNC_OUT) 


#if defined(LaunchSol__INTSTAT)  /* Interrupt Registers */

    #define LaunchSol_INTSTAT                (* (reg8 *) LaunchSol__INTSTAT)
    #define LaunchSol_SNAP                   (* (reg8 *) LaunchSol__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LaunchSol_H */


/* [] END OF FILE */
