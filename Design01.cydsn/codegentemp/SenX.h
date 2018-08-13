/*******************************************************************************
* File Name: SenX.h  
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

#if !defined(CY_PINS_SenX_H) /* Pins SenX_H */
#define CY_PINS_SenX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SenX_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SenX__PORT == 15 && ((SenX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SenX_Write(uint8 value);
void    SenX_SetDriveMode(uint8 mode);
uint8   SenX_ReadDataReg(void);
uint8   SenX_Read(void);
void    SenX_SetInterruptMode(uint16 position, uint16 mode);
uint8   SenX_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SenX_SetDriveMode() function.
     *  @{
     */
        #define SenX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SenX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SenX_DM_RES_UP          PIN_DM_RES_UP
        #define SenX_DM_RES_DWN         PIN_DM_RES_DWN
        #define SenX_DM_OD_LO           PIN_DM_OD_LO
        #define SenX_DM_OD_HI           PIN_DM_OD_HI
        #define SenX_DM_STRONG          PIN_DM_STRONG
        #define SenX_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SenX_MASK               SenX__MASK
#define SenX_SHIFT              SenX__SHIFT
#define SenX_WIDTH              1u

/* Interrupt constants */
#if defined(SenX__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SenX_SetInterruptMode() function.
     *  @{
     */
        #define SenX_INTR_NONE      (uint16)(0x0000u)
        #define SenX_INTR_RISING    (uint16)(0x0001u)
        #define SenX_INTR_FALLING   (uint16)(0x0002u)
        #define SenX_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SenX_INTR_MASK      (0x01u) 
#endif /* (SenX__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SenX_PS                     (* (reg8 *) SenX__PS)
/* Data Register */
#define SenX_DR                     (* (reg8 *) SenX__DR)
/* Port Number */
#define SenX_PRT_NUM                (* (reg8 *) SenX__PRT) 
/* Connect to Analog Globals */                                                  
#define SenX_AG                     (* (reg8 *) SenX__AG)                       
/* Analog MUX bux enable */
#define SenX_AMUX                   (* (reg8 *) SenX__AMUX) 
/* Bidirectional Enable */                                                        
#define SenX_BIE                    (* (reg8 *) SenX__BIE)
/* Bit-mask for Aliased Register Access */
#define SenX_BIT_MASK               (* (reg8 *) SenX__BIT_MASK)
/* Bypass Enable */
#define SenX_BYP                    (* (reg8 *) SenX__BYP)
/* Port wide control signals */                                                   
#define SenX_CTL                    (* (reg8 *) SenX__CTL)
/* Drive Modes */
#define SenX_DM0                    (* (reg8 *) SenX__DM0) 
#define SenX_DM1                    (* (reg8 *) SenX__DM1)
#define SenX_DM2                    (* (reg8 *) SenX__DM2) 
/* Input Buffer Disable Override */
#define SenX_INP_DIS                (* (reg8 *) SenX__INP_DIS)
/* LCD Common or Segment Drive */
#define SenX_LCD_COM_SEG            (* (reg8 *) SenX__LCD_COM_SEG)
/* Enable Segment LCD */
#define SenX_LCD_EN                 (* (reg8 *) SenX__LCD_EN)
/* Slew Rate Control */
#define SenX_SLW                    (* (reg8 *) SenX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SenX_PRTDSI__CAPS_SEL       (* (reg8 *) SenX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SenX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SenX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SenX_PRTDSI__OE_SEL0        (* (reg8 *) SenX__PRTDSI__OE_SEL0) 
#define SenX_PRTDSI__OE_SEL1        (* (reg8 *) SenX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SenX_PRTDSI__OUT_SEL0       (* (reg8 *) SenX__PRTDSI__OUT_SEL0) 
#define SenX_PRTDSI__OUT_SEL1       (* (reg8 *) SenX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SenX_PRTDSI__SYNC_OUT       (* (reg8 *) SenX__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SenX__SIO_CFG)
    #define SenX_SIO_HYST_EN        (* (reg8 *) SenX__SIO_HYST_EN)
    #define SenX_SIO_REG_HIFREQ     (* (reg8 *) SenX__SIO_REG_HIFREQ)
    #define SenX_SIO_CFG            (* (reg8 *) SenX__SIO_CFG)
    #define SenX_SIO_DIFF           (* (reg8 *) SenX__SIO_DIFF)
#endif /* (SenX__SIO_CFG) */

/* Interrupt Registers */
#if defined(SenX__INTSTAT)
    #define SenX_INTSTAT            (* (reg8 *) SenX__INTSTAT)
    #define SenX_SNAP               (* (reg8 *) SenX__SNAP)
    
	#define SenX_0_INTTYPE_REG 		(* (reg8 *) SenX__0__INTTYPE)
#endif /* (SenX__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SenX_H */


/* [] END OF FILE */
