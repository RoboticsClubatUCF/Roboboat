/*******************************************************************************
* File Name: Rx_RBTQ1.h  
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

#if !defined(CY_PINS_Rx_RBTQ1_H) /* Pins Rx_RBTQ1_H */
#define CY_PINS_Rx_RBTQ1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rx_RBTQ1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Rx_RBTQ1_Write(uint8 value) ;
void    Rx_RBTQ1_SetDriveMode(uint8 mode) ;
uint8   Rx_RBTQ1_ReadDataReg(void) ;
uint8   Rx_RBTQ1_Read(void) ;
uint8   Rx_RBTQ1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Rx_RBTQ1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Rx_RBTQ1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Rx_RBTQ1_DM_RES_UP          PIN_DM_RES_UP
#define Rx_RBTQ1_DM_RES_DWN         PIN_DM_RES_DWN
#define Rx_RBTQ1_DM_OD_LO           PIN_DM_OD_LO
#define Rx_RBTQ1_DM_OD_HI           PIN_DM_OD_HI
#define Rx_RBTQ1_DM_STRONG          PIN_DM_STRONG
#define Rx_RBTQ1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Rx_RBTQ1_MASK               Rx_RBTQ1__MASK
#define Rx_RBTQ1_SHIFT              Rx_RBTQ1__SHIFT
#define Rx_RBTQ1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rx_RBTQ1_PS                     (* (reg8 *) Rx_RBTQ1__PS)
/* Data Register */
#define Rx_RBTQ1_DR                     (* (reg8 *) Rx_RBTQ1__DR)
/* Port Number */
#define Rx_RBTQ1_PRT_NUM                (* (reg8 *) Rx_RBTQ1__PRT) 
/* Connect to Analog Globals */                                                  
#define Rx_RBTQ1_AG                     (* (reg8 *) Rx_RBTQ1__AG)                       
/* Analog MUX bux enable */
#define Rx_RBTQ1_AMUX                   (* (reg8 *) Rx_RBTQ1__AMUX) 
/* Bidirectional Enable */                                                        
#define Rx_RBTQ1_BIE                    (* (reg8 *) Rx_RBTQ1__BIE)
/* Bit-mask for Aliased Register Access */
#define Rx_RBTQ1_BIT_MASK               (* (reg8 *) Rx_RBTQ1__BIT_MASK)
/* Bypass Enable */
#define Rx_RBTQ1_BYP                    (* (reg8 *) Rx_RBTQ1__BYP)
/* Port wide control signals */                                                   
#define Rx_RBTQ1_CTL                    (* (reg8 *) Rx_RBTQ1__CTL)
/* Drive Modes */
#define Rx_RBTQ1_DM0                    (* (reg8 *) Rx_RBTQ1__DM0) 
#define Rx_RBTQ1_DM1                    (* (reg8 *) Rx_RBTQ1__DM1)
#define Rx_RBTQ1_DM2                    (* (reg8 *) Rx_RBTQ1__DM2) 
/* Input Buffer Disable Override */
#define Rx_RBTQ1_INP_DIS                (* (reg8 *) Rx_RBTQ1__INP_DIS)
/* LCD Common or Segment Drive */
#define Rx_RBTQ1_LCD_COM_SEG            (* (reg8 *) Rx_RBTQ1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rx_RBTQ1_LCD_EN                 (* (reg8 *) Rx_RBTQ1__LCD_EN)
/* Slew Rate Control */
#define Rx_RBTQ1_SLW                    (* (reg8 *) Rx_RBTQ1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rx_RBTQ1_PRTDSI__CAPS_SEL       (* (reg8 *) Rx_RBTQ1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rx_RBTQ1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rx_RBTQ1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rx_RBTQ1_PRTDSI__OE_SEL0        (* (reg8 *) Rx_RBTQ1__PRTDSI__OE_SEL0) 
#define Rx_RBTQ1_PRTDSI__OE_SEL1        (* (reg8 *) Rx_RBTQ1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rx_RBTQ1_PRTDSI__OUT_SEL0       (* (reg8 *) Rx_RBTQ1__PRTDSI__OUT_SEL0) 
#define Rx_RBTQ1_PRTDSI__OUT_SEL1       (* (reg8 *) Rx_RBTQ1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rx_RBTQ1_PRTDSI__SYNC_OUT       (* (reg8 *) Rx_RBTQ1__PRTDSI__SYNC_OUT) 


#if defined(Rx_RBTQ1__INTSTAT)  /* Interrupt Registers */

    #define Rx_RBTQ1_INTSTAT                (* (reg8 *) Rx_RBTQ1__INTSTAT)
    #define Rx_RBTQ1_SNAP                   (* (reg8 *) Rx_RBTQ1__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Rx_RBTQ1_H */


/* [] END OF FILE */
