/*******************************************************************************
* File Name: strobe.h  
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

#if !defined(CY_PINS_strobe_H) /* Pins strobe_H */
#define CY_PINS_strobe_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "strobe_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    strobe_Write(uint8 value) ;
void    strobe_SetDriveMode(uint8 mode) ;
uint8   strobe_ReadDataReg(void) ;
uint8   strobe_Read(void) ;
uint8   strobe_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define strobe_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define strobe_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define strobe_DM_RES_UP          PIN_DM_RES_UP
#define strobe_DM_RES_DWN         PIN_DM_RES_DWN
#define strobe_DM_OD_LO           PIN_DM_OD_LO
#define strobe_DM_OD_HI           PIN_DM_OD_HI
#define strobe_DM_STRONG          PIN_DM_STRONG
#define strobe_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define strobe_MASK               strobe__MASK
#define strobe_SHIFT              strobe__SHIFT
#define strobe_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define strobe_PS                     (* (reg8 *) strobe__PS)
/* Data Register */
#define strobe_DR                     (* (reg8 *) strobe__DR)
/* Port Number */
#define strobe_PRT_NUM                (* (reg8 *) strobe__PRT) 
/* Connect to Analog Globals */                                                  
#define strobe_AG                     (* (reg8 *) strobe__AG)                       
/* Analog MUX bux enable */
#define strobe_AMUX                   (* (reg8 *) strobe__AMUX) 
/* Bidirectional Enable */                                                        
#define strobe_BIE                    (* (reg8 *) strobe__BIE)
/* Bit-mask for Aliased Register Access */
#define strobe_BIT_MASK               (* (reg8 *) strobe__BIT_MASK)
/* Bypass Enable */
#define strobe_BYP                    (* (reg8 *) strobe__BYP)
/* Port wide control signals */                                                   
#define strobe_CTL                    (* (reg8 *) strobe__CTL)
/* Drive Modes */
#define strobe_DM0                    (* (reg8 *) strobe__DM0) 
#define strobe_DM1                    (* (reg8 *) strobe__DM1)
#define strobe_DM2                    (* (reg8 *) strobe__DM2) 
/* Input Buffer Disable Override */
#define strobe_INP_DIS                (* (reg8 *) strobe__INP_DIS)
/* LCD Common or Segment Drive */
#define strobe_LCD_COM_SEG            (* (reg8 *) strobe__LCD_COM_SEG)
/* Enable Segment LCD */
#define strobe_LCD_EN                 (* (reg8 *) strobe__LCD_EN)
/* Slew Rate Control */
#define strobe_SLW                    (* (reg8 *) strobe__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define strobe_PRTDSI__CAPS_SEL       (* (reg8 *) strobe__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define strobe_PRTDSI__DBL_SYNC_IN    (* (reg8 *) strobe__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define strobe_PRTDSI__OE_SEL0        (* (reg8 *) strobe__PRTDSI__OE_SEL0) 
#define strobe_PRTDSI__OE_SEL1        (* (reg8 *) strobe__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define strobe_PRTDSI__OUT_SEL0       (* (reg8 *) strobe__PRTDSI__OUT_SEL0) 
#define strobe_PRTDSI__OUT_SEL1       (* (reg8 *) strobe__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define strobe_PRTDSI__SYNC_OUT       (* (reg8 *) strobe__PRTDSI__SYNC_OUT) 


#if defined(strobe__INTSTAT)  /* Interrupt Registers */

    #define strobe_INTSTAT                (* (reg8 *) strobe__INTSTAT)
    #define strobe_SNAP                   (* (reg8 *) strobe__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins strobe_H */


/* [] END OF FILE */
