/*******************************************************************************
* File Name: chAx.h  
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

#if !defined(CY_PINS_chAx_H) /* Pins chAx_H */
#define CY_PINS_chAx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "chAx_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 chAx__PORT == 15 && ((chAx__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    chAx_Write(uint8 value);
void    chAx_SetDriveMode(uint8 mode);
uint8   chAx_ReadDataReg(void);
uint8   chAx_Read(void);
void    chAx_SetInterruptMode(uint16 position, uint16 mode);
uint8   chAx_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the chAx_SetDriveMode() function.
     *  @{
     */
        #define chAx_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define chAx_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define chAx_DM_RES_UP          PIN_DM_RES_UP
        #define chAx_DM_RES_DWN         PIN_DM_RES_DWN
        #define chAx_DM_OD_LO           PIN_DM_OD_LO
        #define chAx_DM_OD_HI           PIN_DM_OD_HI
        #define chAx_DM_STRONG          PIN_DM_STRONG
        #define chAx_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define chAx_MASK               chAx__MASK
#define chAx_SHIFT              chAx__SHIFT
#define chAx_WIDTH              1u

/* Interrupt constants */
#if defined(chAx__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in chAx_SetInterruptMode() function.
     *  @{
     */
        #define chAx_INTR_NONE      (uint16)(0x0000u)
        #define chAx_INTR_RISING    (uint16)(0x0001u)
        #define chAx_INTR_FALLING   (uint16)(0x0002u)
        #define chAx_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define chAx_INTR_MASK      (0x01u) 
#endif /* (chAx__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define chAx_PS                     (* (reg8 *) chAx__PS)
/* Data Register */
#define chAx_DR                     (* (reg8 *) chAx__DR)
/* Port Number */
#define chAx_PRT_NUM                (* (reg8 *) chAx__PRT) 
/* Connect to Analog Globals */                                                  
#define chAx_AG                     (* (reg8 *) chAx__AG)                       
/* Analog MUX bux enable */
#define chAx_AMUX                   (* (reg8 *) chAx__AMUX) 
/* Bidirectional Enable */                                                        
#define chAx_BIE                    (* (reg8 *) chAx__BIE)
/* Bit-mask for Aliased Register Access */
#define chAx_BIT_MASK               (* (reg8 *) chAx__BIT_MASK)
/* Bypass Enable */
#define chAx_BYP                    (* (reg8 *) chAx__BYP)
/* Port wide control signals */                                                   
#define chAx_CTL                    (* (reg8 *) chAx__CTL)
/* Drive Modes */
#define chAx_DM0                    (* (reg8 *) chAx__DM0) 
#define chAx_DM1                    (* (reg8 *) chAx__DM1)
#define chAx_DM2                    (* (reg8 *) chAx__DM2) 
/* Input Buffer Disable Override */
#define chAx_INP_DIS                (* (reg8 *) chAx__INP_DIS)
/* LCD Common or Segment Drive */
#define chAx_LCD_COM_SEG            (* (reg8 *) chAx__LCD_COM_SEG)
/* Enable Segment LCD */
#define chAx_LCD_EN                 (* (reg8 *) chAx__LCD_EN)
/* Slew Rate Control */
#define chAx_SLW                    (* (reg8 *) chAx__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define chAx_PRTDSI__CAPS_SEL       (* (reg8 *) chAx__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define chAx_PRTDSI__DBL_SYNC_IN    (* (reg8 *) chAx__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define chAx_PRTDSI__OE_SEL0        (* (reg8 *) chAx__PRTDSI__OE_SEL0) 
#define chAx_PRTDSI__OE_SEL1        (* (reg8 *) chAx__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define chAx_PRTDSI__OUT_SEL0       (* (reg8 *) chAx__PRTDSI__OUT_SEL0) 
#define chAx_PRTDSI__OUT_SEL1       (* (reg8 *) chAx__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define chAx_PRTDSI__SYNC_OUT       (* (reg8 *) chAx__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(chAx__SIO_CFG)
    #define chAx_SIO_HYST_EN        (* (reg8 *) chAx__SIO_HYST_EN)
    #define chAx_SIO_REG_HIFREQ     (* (reg8 *) chAx__SIO_REG_HIFREQ)
    #define chAx_SIO_CFG            (* (reg8 *) chAx__SIO_CFG)
    #define chAx_SIO_DIFF           (* (reg8 *) chAx__SIO_DIFF)
#endif /* (chAx__SIO_CFG) */

/* Interrupt Registers */
#if defined(chAx__INTSTAT)
    #define chAx_INTSTAT            (* (reg8 *) chAx__INTSTAT)
    #define chAx_SNAP               (* (reg8 *) chAx__SNAP)
    
	#define chAx_0_INTTYPE_REG 		(* (reg8 *) chAx__0__INTTYPE)
#endif /* (chAx__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_chAx_H */


/* [] END OF FILE */
