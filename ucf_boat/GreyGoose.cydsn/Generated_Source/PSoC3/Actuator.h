/*******************************************************************************
* File Name: Actuator.h  
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

#if !defined(CY_PINS_Actuator_H) /* Pins Actuator_H */
#define CY_PINS_Actuator_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Actuator_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Actuator_Write(uint8 value) ;
void    Actuator_SetDriveMode(uint8 mode) ;
uint8   Actuator_ReadDataReg(void) ;
uint8   Actuator_Read(void) ;
uint8   Actuator_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Actuator_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Actuator_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Actuator_DM_RES_UP          PIN_DM_RES_UP
#define Actuator_DM_RES_DWN         PIN_DM_RES_DWN
#define Actuator_DM_OD_LO           PIN_DM_OD_LO
#define Actuator_DM_OD_HI           PIN_DM_OD_HI
#define Actuator_DM_STRONG          PIN_DM_STRONG
#define Actuator_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Actuator_MASK               Actuator__MASK
#define Actuator_SHIFT              Actuator__SHIFT
#define Actuator_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Actuator_PS                     (* (reg8 *) Actuator__PS)
/* Data Register */
#define Actuator_DR                     (* (reg8 *) Actuator__DR)
/* Port Number */
#define Actuator_PRT_NUM                (* (reg8 *) Actuator__PRT) 
/* Connect to Analog Globals */                                                  
#define Actuator_AG                     (* (reg8 *) Actuator__AG)                       
/* Analog MUX bux enable */
#define Actuator_AMUX                   (* (reg8 *) Actuator__AMUX) 
/* Bidirectional Enable */                                                        
#define Actuator_BIE                    (* (reg8 *) Actuator__BIE)
/* Bit-mask for Aliased Register Access */
#define Actuator_BIT_MASK               (* (reg8 *) Actuator__BIT_MASK)
/* Bypass Enable */
#define Actuator_BYP                    (* (reg8 *) Actuator__BYP)
/* Port wide control signals */                                                   
#define Actuator_CTL                    (* (reg8 *) Actuator__CTL)
/* Drive Modes */
#define Actuator_DM0                    (* (reg8 *) Actuator__DM0) 
#define Actuator_DM1                    (* (reg8 *) Actuator__DM1)
#define Actuator_DM2                    (* (reg8 *) Actuator__DM2) 
/* Input Buffer Disable Override */
#define Actuator_INP_DIS                (* (reg8 *) Actuator__INP_DIS)
/* LCD Common or Segment Drive */
#define Actuator_LCD_COM_SEG            (* (reg8 *) Actuator__LCD_COM_SEG)
/* Enable Segment LCD */
#define Actuator_LCD_EN                 (* (reg8 *) Actuator__LCD_EN)
/* Slew Rate Control */
#define Actuator_SLW                    (* (reg8 *) Actuator__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Actuator_PRTDSI__CAPS_SEL       (* (reg8 *) Actuator__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Actuator_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Actuator__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Actuator_PRTDSI__OE_SEL0        (* (reg8 *) Actuator__PRTDSI__OE_SEL0) 
#define Actuator_PRTDSI__OE_SEL1        (* (reg8 *) Actuator__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Actuator_PRTDSI__OUT_SEL0       (* (reg8 *) Actuator__PRTDSI__OUT_SEL0) 
#define Actuator_PRTDSI__OUT_SEL1       (* (reg8 *) Actuator__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Actuator_PRTDSI__SYNC_OUT       (* (reg8 *) Actuator__PRTDSI__SYNC_OUT) 


#if defined(Actuator__INTSTAT)  /* Interrupt Registers */

    #define Actuator_INTSTAT                (* (reg8 *) Actuator__INTSTAT)
    #define Actuator_SNAP                   (* (reg8 *) Actuator__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Actuator_H */


/* [] END OF FILE */
