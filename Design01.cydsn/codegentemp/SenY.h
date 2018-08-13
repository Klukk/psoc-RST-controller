/*******************************************************************************
* File Name: SenY.h  
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

#if !defined(CY_PINS_SenY_H) /* Pins SenY_H */
#define CY_PINS_SenY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SenY_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SenY__PORT == 15 && ((SenY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SenY_Write(uint8 value);
void    SenY_SetDriveMode(uint8 mode);
uint8   SenY_ReadDataReg(void);
uint8   SenY_Read(void);
void    SenY_SetInterruptMode(uint16 position, uint16 mode);
uint8   SenY_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SenY_SetDriveMode() function.
     *  @{
     */
        #define SenY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SenY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SenY_DM_RES_UP          PIN_DM_RES_UP
        #define SenY_DM_RES_DWN         PIN_DM_RES_DWN
        #define SenY_DM_OD_LO           PIN_DM_OD_LO
        #define SenY_DM_OD_HI           PIN_DM_OD_HI
        #define SenY_DM_STRONG          PIN_DM_STRONG
        #define SenY_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SenY_MASK               SenY__MASK
#define SenY_SHIFT              SenY__SHIFT
#define SenY_WIDTH              1u

/* Interrupt constants */
#if defined(SenY__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SenY_SetInterruptMode() function.
     *  @{
     */
        #define SenY_INTR_NONE      (uint16)(0x0000u)
        #define SenY_INTR_RISING    (uint16)(0x0001u)
        #define SenY_INTR_FALLING   (uint16)(0x0002u)
        #define SenY_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SenY_INTR_MASK      (0x01u) 
#endif /* (SenY__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SenY_PS                     (* (reg8 *) SenY__PS)
/* Data Register */
#define SenY_DR                     (* (reg8 *) SenY__DR)
/* Port Number */
#define SenY_PRT_NUM                (* (reg8 *) SenY__PRT) 
/* Connect to Analog Globals */                                                  
#define SenY_AG                     (* (reg8 *) SenY__AG)                       
/* Analog MUX bux enable */
#define SenY_AMUX                   (* (reg8 *) SenY__AMUX) 
/* Bidirectional Enable */                                                        
#define SenY_BIE                    (* (reg8 *) SenY__BIE)
/* Bit-mask for Aliased Register Access */
#define SenY_BIT_MASK               (* (reg8 *) SenY__BIT_MASK)
/* Bypass Enable */
#define SenY_BYP                    (* (reg8 *) SenY__BYP)
/* Port wide control signals */                                                   
#define SenY_CTL                    (* (reg8 *) SenY__CTL)
/* Drive Modes */
#define SenY_DM0                    (* (reg8 *) SenY__DM0) 
#define SenY_DM1                    (* (reg8 *) SenY__DM1)
#define SenY_DM2                    (* (reg8 *) SenY__DM2) 
/* Input Buffer Disable Override */
#define SenY_INP_DIS                (* (reg8 *) SenY__INP_DIS)
/* LCD Common or Segment Drive */
#define SenY_LCD_COM_SEG            (* (reg8 *) SenY__LCD_COM_SEG)
/* Enable Segment LCD */
#define SenY_LCD_EN                 (* (reg8 *) SenY__LCD_EN)
/* Slew Rate Control */
#define SenY_SLW                    (* (reg8 *) SenY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SenY_PRTDSI__CAPS_SEL       (* (reg8 *) SenY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SenY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SenY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SenY_PRTDSI__OE_SEL0        (* (reg8 *) SenY__PRTDSI__OE_SEL0) 
#define SenY_PRTDSI__OE_SEL1        (* (reg8 *) SenY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SenY_PRTDSI__OUT_SEL0       (* (reg8 *) SenY__PRTDSI__OUT_SEL0) 
#define SenY_PRTDSI__OUT_SEL1       (* (reg8 *) SenY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SenY_PRTDSI__SYNC_OUT       (* (reg8 *) SenY__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SenY__SIO_CFG)
    #define SenY_SIO_HYST_EN        (* (reg8 *) SenY__SIO_HYST_EN)
    #define SenY_SIO_REG_HIFREQ     (* (reg8 *) SenY__SIO_REG_HIFREQ)
    #define SenY_SIO_CFG            (* (reg8 *) SenY__SIO_CFG)
    #define SenY_SIO_DIFF           (* (reg8 *) SenY__SIO_DIFF)
#endif /* (SenY__SIO_CFG) */

/* Interrupt Registers */
#if defined(SenY__INTSTAT)
    #define SenY_INTSTAT            (* (reg8 *) SenY__INTSTAT)
    #define SenY_SNAP               (* (reg8 *) SenY__SNAP)
    
	#define SenY_0_INTTYPE_REG 		(* (reg8 *) SenY__0__INTTYPE)
#endif /* (SenY__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SenY_H */


/* [] END OF FILE */
