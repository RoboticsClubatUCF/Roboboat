/*******************************************************************************
* File Name: BATT_MOTOR.h  
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

#if !defined(CY_PINS_BATT_MOTOR_H) /* Pins BATT_MOTOR_H */
#define CY_PINS_BATT_MOTOR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BATT_MOTOR_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BATT_MOTOR_Write(uint8 value) ;
void    BATT_MOTOR_SetDriveMode(uint8 mode) ;
uint8   BATT_MOTOR_ReadDataReg(void) ;
uint8   BATT_MOTOR_Read(void) ;
uint8   BATT_MOTOR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BATT_MOTOR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BATT_MOTOR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BATT_MOTOR_DM_RES_UP          PIN_DM_RES_UP
#define BATT_MOTOR_DM_RES_DWN         PIN_DM_RES_DWN
#define BATT_MOTOR_DM_OD_LO           PIN_DM_OD_LO
#define BATT_MOTOR_DM_OD_HI           PIN_DM_OD_HI
#define BATT_MOTOR_DM_STRONG          PIN_DM_STRONG
#define BATT_MOTOR_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BATT_MOTOR_MASK               BATT_MOTOR__MASK
#define BATT_MOTOR_SHIFT              BATT_MOTOR__SHIFT
#define BATT_MOTOR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BATT_MOTOR_PS                     (* (reg8 *) BATT_MOTOR__PS)
/* Data Register */
#define BATT_MOTOR_DR                     (* (reg8 *) BATT_MOTOR__DR)
/* Port Number */
#define BATT_MOTOR_PRT_NUM                (* (reg8 *) BATT_MOTOR__PRT) 
/* Connect to Analog Globals */                                                  
#define BATT_MOTOR_AG                     (* (reg8 *) BATT_MOTOR__AG)                       
/* Analog MUX bux enable */
#define BATT_MOTOR_AMUX                   (* (reg8 *) BATT_MOTOR__AMUX) 
/* Bidirectional Enable */                                                        
#define BATT_MOTOR_BIE                    (* (reg8 *) BATT_MOTOR__BIE)
/* Bit-mask for Aliased Register Access */
#define BATT_MOTOR_BIT_MASK               (* (reg8 *) BATT_MOTOR__BIT_MASK)
/* Bypass Enable */
#define BATT_MOTOR_BYP                    (* (reg8 *) BATT_MOTOR__BYP)
/* Port wide control signals */                                                   
#define BATT_MOTOR_CTL                    (* (reg8 *) BATT_MOTOR__CTL)
/* Drive Modes */
#define BATT_MOTOR_DM0                    (* (reg8 *) BATT_MOTOR__DM0) 
#define BATT_MOTOR_DM1                    (* (reg8 *) BATT_MOTOR__DM1)
#define BATT_MOTOR_DM2                    (* (reg8 *) BATT_MOTOR__DM2) 
/* Input Buffer Disable Override */
#define BATT_MOTOR_INP_DIS                (* (reg8 *) BATT_MOTOR__INP_DIS)
/* LCD Common or Segment Drive */
#define BATT_MOTOR_LCD_COM_SEG            (* (reg8 *) BATT_MOTOR__LCD_COM_SEG)
/* Enable Segment LCD */
#define BATT_MOTOR_LCD_EN                 (* (reg8 *) BATT_MOTOR__LCD_EN)
/* Slew Rate Control */
#define BATT_MOTOR_SLW                    (* (reg8 *) BATT_MOTOR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BATT_MOTOR_PRTDSI__CAPS_SEL       (* (reg8 *) BATT_MOTOR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BATT_MOTOR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BATT_MOTOR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BATT_MOTOR_PRTDSI__OE_SEL0        (* (reg8 *) BATT_MOTOR__PRTDSI__OE_SEL0) 
#define BATT_MOTOR_PRTDSI__OE_SEL1        (* (reg8 *) BATT_MOTOR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BATT_MOTOR_PRTDSI__OUT_SEL0       (* (reg8 *) BATT_MOTOR__PRTDSI__OUT_SEL0) 
#define BATT_MOTOR_PRTDSI__OUT_SEL1       (* (reg8 *) BATT_MOTOR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BATT_MOTOR_PRTDSI__SYNC_OUT       (* (reg8 *) BATT_MOTOR__PRTDSI__SYNC_OUT) 


#if defined(BATT_MOTOR__INTSTAT)  /* Interrupt Registers */

    #define BATT_MOTOR_INTSTAT                (* (reg8 *) BATT_MOTOR__INTSTAT)
    #define BATT_MOTOR_SNAP                   (* (reg8 *) BATT_MOTOR__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins BATT_MOTOR_H */


/* [] END OF FILE */
