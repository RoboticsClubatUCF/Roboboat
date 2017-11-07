/*******************************************************************************
* File Name: TestPin.h  
* Version 1.60
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_TestPin_H) /* Pins TestPin_H */
#define CY_PINS_TestPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TestPin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TestPin_Write(uint8 value) ;
void    TestPin_SetDriveMode(uint8 mode) ;
uint8   TestPin_ReadDataReg(void) ;
uint8   TestPin_Read(void) ;
uint8   TestPin_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TestPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TestPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TestPin_DM_RES_UP          PIN_DM_RES_UP
#define TestPin_DM_RES_DWN         PIN_DM_RES_DWN
#define TestPin_DM_OD_LO           PIN_DM_OD_LO
#define TestPin_DM_OD_HI           PIN_DM_OD_HI
#define TestPin_DM_STRONG          PIN_DM_STRONG
#define TestPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TestPin_MASK               TestPin__MASK
#define TestPin_SHIFT              TestPin__SHIFT
#define TestPin_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TestPin_PS                     (* (reg8 *) TestPin__PS)
/* Data Register */
#define TestPin_DR                     (* (reg8 *) TestPin__DR)
/* Port Number */
#define TestPin_PRT_NUM                (* (reg8 *) TestPin__PRT) 
/* Connect to Analog Globals */                                                  
#define TestPin_AG                     (* (reg8 *) TestPin__AG)                       
/* Analog MUX bux enable */
#define TestPin_AMUX                   (* (reg8 *) TestPin__AMUX) 
/* Bidirectional Enable */                                                        
#define TestPin_BIE                    (* (reg8 *) TestPin__BIE)
/* Bit-mask for Aliased Register Access */
#define TestPin_BIT_MASK               (* (reg8 *) TestPin__BIT_MASK)
/* Bypass Enable */
#define TestPin_BYP                    (* (reg8 *) TestPin__BYP)
/* Port wide control signals */                                                   
#define TestPin_CTL                    (* (reg8 *) TestPin__CTL)
/* Drive Modes */
#define TestPin_DM0                    (* (reg8 *) TestPin__DM0) 
#define TestPin_DM1                    (* (reg8 *) TestPin__DM1)
#define TestPin_DM2                    (* (reg8 *) TestPin__DM2) 
/* Input Buffer Disable Override */
#define TestPin_INP_DIS                (* (reg8 *) TestPin__INP_DIS)
/* LCD Common or Segment Drive */
#define TestPin_LCD_COM_SEG            (* (reg8 *) TestPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define TestPin_LCD_EN                 (* (reg8 *) TestPin__LCD_EN)
/* Slew Rate Control */
#define TestPin_SLW                    (* (reg8 *) TestPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TestPin_PRTDSI__CAPS_SEL       (* (reg8 *) TestPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TestPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TestPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TestPin_PRTDSI__OE_SEL0        (* (reg8 *) TestPin__PRTDSI__OE_SEL0) 
#define TestPin_PRTDSI__OE_SEL1        (* (reg8 *) TestPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TestPin_PRTDSI__OUT_SEL0       (* (reg8 *) TestPin__PRTDSI__OUT_SEL0) 
#define TestPin_PRTDSI__OUT_SEL1       (* (reg8 *) TestPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TestPin_PRTDSI__SYNC_OUT       (* (reg8 *) TestPin__PRTDSI__SYNC_OUT) 


#if defined(TestPin__INTSTAT)  /* Interrupt Registers */

    #define TestPin_INTSTAT                (* (reg8 *) TestPin__INTSTAT)
    #define TestPin_SNAP                   (* (reg8 *) TestPin__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins TestPin_H */


/* [] END OF FILE */
