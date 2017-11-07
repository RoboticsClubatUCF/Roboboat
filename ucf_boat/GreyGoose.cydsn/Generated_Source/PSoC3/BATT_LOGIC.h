/*******************************************************************************
* File Name: BATT_LOGIC.h  
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

#if !defined(CY_PINS_BATT_LOGIC_H) /* Pins BATT_LOGIC_H */
#define CY_PINS_BATT_LOGIC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BATT_LOGIC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BATT_LOGIC_Write(uint8 value) ;
void    BATT_LOGIC_SetDriveMode(uint8 mode) ;
uint8   BATT_LOGIC_ReadDataReg(void) ;
uint8   BATT_LOGIC_Read(void) ;
uint8   BATT_LOGIC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BATT_LOGIC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BATT_LOGIC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BATT_LOGIC_DM_RES_UP          PIN_DM_RES_UP
#define BATT_LOGIC_DM_RES_DWN         PIN_DM_RES_DWN
#define BATT_LOGIC_DM_OD_LO           PIN_DM_OD_LO
#define BATT_LOGIC_DM_OD_HI           PIN_DM_OD_HI
#define BATT_LOGIC_DM_STRONG          PIN_DM_STRONG
#define BATT_LOGIC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BATT_LOGIC_MASK               BATT_LOGIC__MASK
#define BATT_LOGIC_SHIFT              BATT_LOGIC__SHIFT
#define BATT_LOGIC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BATT_LOGIC_PS                     (* (reg8 *) BATT_LOGIC__PS)
/* Data Register */
#define BATT_LOGIC_DR                     (* (reg8 *) BATT_LOGIC__DR)
/* Port Number */
#define BATT_LOGIC_PRT_NUM                (* (reg8 *) BATT_LOGIC__PRT) 
/* Connect to Analog Globals */                                                  
#define BATT_LOGIC_AG                     (* (reg8 *) BATT_LOGIC__AG)                       
/* Analog MUX bux enable */
#define BATT_LOGIC_AMUX                   (* (reg8 *) BATT_LOGIC__AMUX) 
/* Bidirectional Enable */                                                        
#define BATT_LOGIC_BIE                    (* (reg8 *) BATT_LOGIC__BIE)
/* Bit-mask for Aliased Register Access */
#define BATT_LOGIC_BIT_MASK               (* (reg8 *) BATT_LOGIC__BIT_MASK)
/* Bypass Enable */
#define BATT_LOGIC_BYP                    (* (reg8 *) BATT_LOGIC__BYP)
/* Port wide control signals */                                                   
#define BATT_LOGIC_CTL                    (* (reg8 *) BATT_LOGIC__CTL)
/* Drive Modes */
#define BATT_LOGIC_DM0                    (* (reg8 *) BATT_LOGIC__DM0) 
#define BATT_LOGIC_DM1                    (* (reg8 *) BATT_LOGIC__DM1)
#define BATT_LOGIC_DM2                    (* (reg8 *) BATT_LOGIC__DM2) 
/* Input Buffer Disable Override */
#define BATT_LOGIC_INP_DIS                (* (reg8 *) BATT_LOGIC__INP_DIS)
/* LCD Common or Segment Drive */
#define BATT_LOGIC_LCD_COM_SEG            (* (reg8 *) BATT_LOGIC__LCD_COM_SEG)
/* Enable Segment LCD */
#define BATT_LOGIC_LCD_EN                 (* (reg8 *) BATT_LOGIC__LCD_EN)
/* Slew Rate Control */
#define BATT_LOGIC_SLW                    (* (reg8 *) BATT_LOGIC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BATT_LOGIC_PRTDSI__CAPS_SEL       (* (reg8 *) BATT_LOGIC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BATT_LOGIC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BATT_LOGIC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BATT_LOGIC_PRTDSI__OE_SEL0        (* (reg8 *) BATT_LOGIC__PRTDSI__OE_SEL0) 
#define BATT_LOGIC_PRTDSI__OE_SEL1        (* (reg8 *) BATT_LOGIC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BATT_LOGIC_PRTDSI__OUT_SEL0       (* (reg8 *) BATT_LOGIC__PRTDSI__OUT_SEL0) 
#define BATT_LOGIC_PRTDSI__OUT_SEL1       (* (reg8 *) BATT_LOGIC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BATT_LOGIC_PRTDSI__SYNC_OUT       (* (reg8 *) BATT_LOGIC__PRTDSI__SYNC_OUT) 


#if defined(BATT_LOGIC__INTSTAT)  /* Interrupt Registers */

    #define BATT_LOGIC_INTSTAT                (* (reg8 *) BATT_LOGIC__INTSTAT)
    #define BATT_LOGIC_SNAP                   (* (reg8 *) BATT_LOGIC__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins BATT_LOGIC_H */


/* [] END OF FILE */
