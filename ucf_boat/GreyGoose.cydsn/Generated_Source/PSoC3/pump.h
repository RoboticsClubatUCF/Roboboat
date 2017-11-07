/*******************************************************************************
* File Name: pump.h  
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

#if !defined(CY_PINS_pump_H) /* Pins pump_H */
#define CY_PINS_pump_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pump_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pump_Write(uint8 value) ;
void    pump_SetDriveMode(uint8 mode) ;
uint8   pump_ReadDataReg(void) ;
uint8   pump_Read(void) ;
uint8   pump_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pump_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define pump_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define pump_DM_RES_UP          PIN_DM_RES_UP
#define pump_DM_RES_DWN         PIN_DM_RES_DWN
#define pump_DM_OD_LO           PIN_DM_OD_LO
#define pump_DM_OD_HI           PIN_DM_OD_HI
#define pump_DM_STRONG          PIN_DM_STRONG
#define pump_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define pump_MASK               pump__MASK
#define pump_SHIFT              pump__SHIFT
#define pump_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pump_PS                     (* (reg8 *) pump__PS)
/* Data Register */
#define pump_DR                     (* (reg8 *) pump__DR)
/* Port Number */
#define pump_PRT_NUM                (* (reg8 *) pump__PRT) 
/* Connect to Analog Globals */                                                  
#define pump_AG                     (* (reg8 *) pump__AG)                       
/* Analog MUX bux enable */
#define pump_AMUX                   (* (reg8 *) pump__AMUX) 
/* Bidirectional Enable */                                                        
#define pump_BIE                    (* (reg8 *) pump__BIE)
/* Bit-mask for Aliased Register Access */
#define pump_BIT_MASK               (* (reg8 *) pump__BIT_MASK)
/* Bypass Enable */
#define pump_BYP                    (* (reg8 *) pump__BYP)
/* Port wide control signals */                                                   
#define pump_CTL                    (* (reg8 *) pump__CTL)
/* Drive Modes */
#define pump_DM0                    (* (reg8 *) pump__DM0) 
#define pump_DM1                    (* (reg8 *) pump__DM1)
#define pump_DM2                    (* (reg8 *) pump__DM2) 
/* Input Buffer Disable Override */
#define pump_INP_DIS                (* (reg8 *) pump__INP_DIS)
/* LCD Common or Segment Drive */
#define pump_LCD_COM_SEG            (* (reg8 *) pump__LCD_COM_SEG)
/* Enable Segment LCD */
#define pump_LCD_EN                 (* (reg8 *) pump__LCD_EN)
/* Slew Rate Control */
#define pump_SLW                    (* (reg8 *) pump__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pump_PRTDSI__CAPS_SEL       (* (reg8 *) pump__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pump_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pump__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pump_PRTDSI__OE_SEL0        (* (reg8 *) pump__PRTDSI__OE_SEL0) 
#define pump_PRTDSI__OE_SEL1        (* (reg8 *) pump__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pump_PRTDSI__OUT_SEL0       (* (reg8 *) pump__PRTDSI__OUT_SEL0) 
#define pump_PRTDSI__OUT_SEL1       (* (reg8 *) pump__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pump_PRTDSI__SYNC_OUT       (* (reg8 *) pump__PRTDSI__SYNC_OUT) 


#if defined(pump__INTSTAT)  /* Interrupt Registers */

    #define pump_INTSTAT                (* (reg8 *) pump__INTSTAT)
    #define pump_SNAP                   (* (reg8 *) pump__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins pump_H */


/* [] END OF FILE */
