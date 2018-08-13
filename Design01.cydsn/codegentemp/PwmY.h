/*******************************************************************************
* File Name: PwmY.h  
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

#if !defined(CY_PINS_PwmY_H) /* Pins PwmY_H */
#define CY_PINS_PwmY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PwmY_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PwmY__PORT == 15 && ((PwmY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PwmY_Write(uint8 value);
void    PwmY_SetDriveMode(uint8 mode);
uint8   PwmY_ReadDataReg(void);
uint8   PwmY_Read(void);
void    PwmY_SetInterruptMode(uint16 position, uint16 mode);
uint8   PwmY_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PwmY_SetDriveMode() function.
     *  @{
     */
        #define PwmY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PwmY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PwmY_DM_RES_UP          PIN_DM_RES_UP
        #define PwmY_DM_RES_DWN         PIN_DM_RES_DWN
        #define PwmY_DM_OD_LO           PIN_DM_OD_LO
        #define PwmY_DM_OD_HI           PIN_DM_OD_HI
        #define PwmY_DM_STRONG          PIN_DM_STRONG
        #define PwmY_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PwmY_MASK               PwmY__MASK
#define PwmY_SHIFT              PwmY__SHIFT
#define PwmY_WIDTH              1u

/* Interrupt constants */
#if defined(PwmY__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PwmY_SetInterruptMode() function.
     *  @{
     */
        #define PwmY_INTR_NONE      (uint16)(0x0000u)
        #define PwmY_INTR_RISING    (uint16)(0x0001u)
        #define PwmY_INTR_FALLING   (uint16)(0x0002u)
        #define PwmY_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PwmY_INTR_MASK      (0x01u) 
#endif /* (PwmY__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PwmY_PS                     (* (reg8 *) PwmY__PS)
/* Data Register */
#define PwmY_DR                     (* (reg8 *) PwmY__DR)
/* Port Number */
#define PwmY_PRT_NUM                (* (reg8 *) PwmY__PRT) 
/* Connect to Analog Globals */                                                  
#define PwmY_AG                     (* (reg8 *) PwmY__AG)                       
/* Analog MUX bux enable */
#define PwmY_AMUX                   (* (reg8 *) PwmY__AMUX) 
/* Bidirectional Enable */                                                        
#define PwmY_BIE                    (* (reg8 *) PwmY__BIE)
/* Bit-mask for Aliased Register Access */
#define PwmY_BIT_MASK               (* (reg8 *) PwmY__BIT_MASK)
/* Bypass Enable */
#define PwmY_BYP                    (* (reg8 *) PwmY__BYP)
/* Port wide control signals */                                                   
#define PwmY_CTL                    (* (reg8 *) PwmY__CTL)
/* Drive Modes */
#define PwmY_DM0                    (* (reg8 *) PwmY__DM0) 
#define PwmY_DM1                    (* (reg8 *) PwmY__DM1)
#define PwmY_DM2                    (* (reg8 *) PwmY__DM2) 
/* Input Buffer Disable Override */
#define PwmY_INP_DIS                (* (reg8 *) PwmY__INP_DIS)
/* LCD Common or Segment Drive */
#define PwmY_LCD_COM_SEG            (* (reg8 *) PwmY__LCD_COM_SEG)
/* Enable Segment LCD */
#define PwmY_LCD_EN                 (* (reg8 *) PwmY__LCD_EN)
/* Slew Rate Control */
#define PwmY_SLW                    (* (reg8 *) PwmY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PwmY_PRTDSI__CAPS_SEL       (* (reg8 *) PwmY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PwmY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PwmY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PwmY_PRTDSI__OE_SEL0        (* (reg8 *) PwmY__PRTDSI__OE_SEL0) 
#define PwmY_PRTDSI__OE_SEL1        (* (reg8 *) PwmY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PwmY_PRTDSI__OUT_SEL0       (* (reg8 *) PwmY__PRTDSI__OUT_SEL0) 
#define PwmY_PRTDSI__OUT_SEL1       (* (reg8 *) PwmY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PwmY_PRTDSI__SYNC_OUT       (* (reg8 *) PwmY__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PwmY__SIO_CFG)
    #define PwmY_SIO_HYST_EN        (* (reg8 *) PwmY__SIO_HYST_EN)
    #define PwmY_SIO_REG_HIFREQ     (* (reg8 *) PwmY__SIO_REG_HIFREQ)
    #define PwmY_SIO_CFG            (* (reg8 *) PwmY__SIO_CFG)
    #define PwmY_SIO_DIFF           (* (reg8 *) PwmY__SIO_DIFF)
#endif /* (PwmY__SIO_CFG) */

/* Interrupt Registers */
#if defined(PwmY__INTSTAT)
    #define PwmY_INTSTAT            (* (reg8 *) PwmY__INTSTAT)
    #define PwmY_SNAP               (* (reg8 *) PwmY__SNAP)
    
	#define PwmY_0_INTTYPE_REG 		(* (reg8 *) PwmY__0__INTTYPE)
#endif /* (PwmY__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PwmY_H */


/* [] END OF FILE */
