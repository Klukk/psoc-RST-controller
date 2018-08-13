/*******************************************************************************
* File Name: chBy.h  
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

#if !defined(CY_PINS_chBy_H) /* Pins chBy_H */
#define CY_PINS_chBy_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chBy_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chBy__PORT == 15 && ((chBy__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chBy_Write(uint8 value);
void    chBy_SetDriveMode(uint8 mode);
uint8   chBy_ReadDataReg(void);
uint8   chBy_Read(void);
void    chBy_SetInterruptMode(uint16 position, uint16 mode);
uint8   chBy_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chBy_SetDriveMode() function.
     *  @{
     */
        #define chBy_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chBy_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chBy_DM_RES_UP          PIN_DM_RES_UP
        #define chBy_DM_RES_DWN         PIN_DM_RES_DWN
        #define chBy_DM_OD_LO           PIN_DM_OD_LO
        #define chBy_DM_OD_HI           PIN_DM_OD_HI
        #define chBy_DM_STRONG          PIN_DM_STRONG
        #define chBy_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chBy_MASK               chBy__MASK
#define chBy_SHIFT              chBy__SHIFT
#define chBy_WIDTH              1u

/* Interrupt constants */
#if defined(chBy__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chBy_SetInterruptMode() function.
     *  @{
     */
        #define chBy_INTR_NONE      (uint16)(0x0000u)
        #define chBy_INTR_RISING    (uint16)(0x0001u)
        #define chBy_INTR_FALLING   (uint16)(0x0002u)
        #define chBy_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chBy_INTR_MASK      (0x01u) 
#endif /* (chBy__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chBy_PS                     (* (reg8 *) chBy__PS)
/* Data Register */
#define chBy_DR                     (* (reg8 *) chBy__DR)
/* Port Number */
#define chBy_PRT_NUM                (* (reg8 *) chBy__PRT) 
/* Connect to Analog Globals */                                                  
#define chBy_AG                     (* (reg8 *) chBy__AG)                       
/* Analog MUX bux enable */
#define chBy_AMUX                   (* (reg8 *) chBy__AMUX) 
/* Bidirectional Enable */                                                        
#define chBy_BIE                    (* (reg8 *) chBy__BIE)
/* Bit-mask for Aliased Register Access */
#define chBy_BIT_MASK               (* (reg8 *) chBy__BIT_MASK)
/* Bypass Enable */
#define chBy_BYP                    (* (reg8 *) chBy__BYP)
/* Port wide control signals */                                                   
#define chBy_CTL                    (* (reg8 *) chBy__CTL)
/* Drive Modes */
#define chBy_DM0                    (* (reg8 *) chBy__DM0) 
#define chBy_DM1                    (* (reg8 *) chBy__DM1)
#define chBy_DM2                    (* (reg8 *) chBy__DM2) 
/* Input Buffer Disable Override */
#define chBy_INP_DIS                (* (reg8 *) chBy__INP_DIS)
/* LCD Common or Segment Drive */
#define chBy_LCD_COM_SEG            (* (reg8 *) chBy__LCD_COM_SEG)
/* Enable Segment LCD */
#define chBy_LCD_EN                 (* (reg8 *) chBy__LCD_EN)
/* Slew Rate Control */
#define chBy_SLW                    (* (reg8 *) chBy__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chBy_PRTDSI__CAPS_SEL       (* (reg8 *) chBy__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chBy_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chBy__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chBy_PRTDSI__OE_SEL0        (* (reg8 *) chBy__PRTDSI__OE_SEL0) 
#define chBy_PRTDSI__OE_SEL1        (* (reg8 *) chBy__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chBy_PRTDSI__OUT_SEL0       (* (reg8 *) chBy__PRTDSI__OUT_SEL0) 
#define chBy_PRTDSI__OUT_SEL1       (* (reg8 *) chBy__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chBy_PRTDSI__SYNC_OUT       (* (reg8 *) chBy__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chBy__SIO_CFG)
    #define chBy_SIO_HYST_EN        (* (reg8 *) chBy__SIO_HYST_EN)
    #define chBy_SIO_REG_HIFREQ     (* (reg8 *) chBy__SIO_REG_HIFREQ)
    #define chBy_SIO_CFG            (* (reg8 *) chBy__SIO_CFG)
    #define chBy_SIO_DIFF           (* (reg8 *) chBy__SIO_DIFF)
#endif /* (chBy__SIO_CFG) */

/* Interrupt Registers */
#if defined(chBy__INTSTAT)
    #define chBy_INTSTAT            (* (reg8 *) chBy__INTSTAT)
    #define chBy_SNAP               (* (reg8 *) chBy__SNAP)
    
	#define chBy_0_INTTYPE_REG 		(* (reg8 *) chBy__0__INTTYPE)
#endif /* (chBy__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chBy_H */


/* [] END OF FILE */
