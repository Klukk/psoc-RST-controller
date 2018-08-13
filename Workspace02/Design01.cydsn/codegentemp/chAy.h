/*******************************************************************************
* File Name: chAy.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_chAy_H) /* Pins chAy_H */
#define CY_PINS_chAy_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chAy_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chAy__PORT == 15 && ((chAy__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chAy_Write(uint8 value);
void    chAy_SetDriveMode(uint8 mode);
uint8   chAy_ReadDataReg(void);
uint8   chAy_Read(void);
void    chAy_SetInterruptMode(uint16 position, uint16 mode);
uint8   chAy_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chAy_SetDriveMode() function.
     *  @{
     */
        #define chAy_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chAy_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chAy_DM_RES_UP          PIN_DM_RES_UP
        #define chAy_DM_RES_DWN         PIN_DM_RES_DWN
        #define chAy_DM_OD_LO           PIN_DM_OD_LO
        #define chAy_DM_OD_HI           PIN_DM_OD_HI
        #define chAy_DM_STRONG          PIN_DM_STRONG
        #define chAy_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chAy_MASK               chAy__MASK
#define chAy_SHIFT              chAy__SHIFT
#define chAy_WIDTH              1u

/* Interrupt constants */
#if defined(chAy__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chAy_SetInterruptMode() function.
     *  @{
     */
        #define chAy_INTR_NONE      (uint16)(0x0000u)
        #define chAy_INTR_RISING    (uint16)(0x0001u)
        #define chAy_INTR_FALLING   (uint16)(0x0002u)
        #define chAy_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chAy_INTR_MASK      (0x01u) 
#endif /* (chAy__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chAy_PS                     (* (reg8 *) chAy__PS)
/* Data Register */
#define chAy_DR                     (* (reg8 *) chAy__DR)
/* Port Number */
#define chAy_PRT_NUM                (* (reg8 *) chAy__PRT) 
/* Connect to Analog Globals */                                                  
#define chAy_AG                     (* (reg8 *) chAy__AG)                       
/* Analog MUX bux enable */
#define chAy_AMUX                   (* (reg8 *) chAy__AMUX) 
/* Bidirectional Enable */                                                        
#define chAy_BIE                    (* (reg8 *) chAy__BIE)
/* Bit-mask for Aliased Register Access */
#define chAy_BIT_MASK               (* (reg8 *) chAy__BIT_MASK)
/* Bypass Enable */
#define chAy_BYP                    (* (reg8 *) chAy__BYP)
/* Port wide control signals */                                                   
#define chAy_CTL                    (* (reg8 *) chAy__CTL)
/* Drive Modes */
#define chAy_DM0                    (* (reg8 *) chAy__DM0) 
#define chAy_DM1                    (* (reg8 *) chAy__DM1)
#define chAy_DM2                    (* (reg8 *) chAy__DM2) 
/* Input Buffer Disable Override */
#define chAy_INP_DIS                (* (reg8 *) chAy__INP_DIS)
/* LCD Common or Segment Drive */
#define chAy_LCD_COM_SEG            (* (reg8 *) chAy__LCD_COM_SEG)
/* Enable Segment LCD */
#define chAy_LCD_EN                 (* (reg8 *) chAy__LCD_EN)
/* Slew Rate Control */
#define chAy_SLW                    (* (reg8 *) chAy__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chAy_PRTDSI__CAPS_SEL       (* (reg8 *) chAy__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chAy_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chAy__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chAy_PRTDSI__OE_SEL0        (* (reg8 *) chAy__PRTDSI__OE_SEL0) 
#define chAy_PRTDSI__OE_SEL1        (* (reg8 *) chAy__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chAy_PRTDSI__OUT_SEL0       (* (reg8 *) chAy__PRTDSI__OUT_SEL0) 
#define chAy_PRTDSI__OUT_SEL1       (* (reg8 *) chAy__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chAy_PRTDSI__SYNC_OUT       (* (reg8 *) chAy__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chAy__SIO_CFG)
    #define chAy_SIO_HYST_EN        (* (reg8 *) chAy__SIO_HYST_EN)
    #define chAy_SIO_REG_HIFREQ     (* (reg8 *) chAy__SIO_REG_HIFREQ)
    #define chAy_SIO_CFG            (* (reg8 *) chAy__SIO_CFG)
    #define chAy_SIO_DIFF           (* (reg8 *) chAy__SIO_DIFF)
#endif /* (chAy__SIO_CFG) */

/* Interrupt Registers */
#if defined(chAy__INTSTAT)
    #define chAy_INTSTAT            (* (reg8 *) chAy__INTSTAT)
    #define chAy_SNAP               (* (reg8 *) chAy__SNAP)
    
	#define chAy_0_INTTYPE_REG 		(* (reg8 *) chAy__0__INTTYPE)
#endif /* (chAy__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chAy_H */


/* [] END OF FILE */
