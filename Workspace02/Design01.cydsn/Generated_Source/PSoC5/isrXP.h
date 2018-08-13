/*******************************************************************************
* File Name: isrXP.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isrXP_H)
#define CY_ISR_isrXP_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrXP_Start(void);
void isrXP_StartEx(cyisraddress address);
void isrXP_Stop(void);

CY_ISR_PROTO(isrXP_Interrupt);

void isrXP_SetVector(cyisraddress address);
cyisraddress isrXP_GetVector(void);

void isrXP_SetPriority(uint8 priority);
uint8 isrXP_GetPriority(void);

void isrXP_Enable(void);
uint8 isrXP_GetState(void);
void isrXP_Disable(void);

void isrXP_SetPending(void);
void isrXP_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrXP ISR. */
#define isrXP_INTC_VECTOR            ((reg32 *) isrXP__INTC_VECT)

/* Address of the isrXP ISR priority. */
#define isrXP_INTC_PRIOR             ((reg8 *) isrXP__INTC_PRIOR_REG)

/* Priority of the isrXP interrupt. */
#define isrXP_INTC_PRIOR_NUMBER      isrXP__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrXP interrupt. */
#define isrXP_INTC_SET_EN            ((reg32 *) isrXP__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrXP interrupt. */
#define isrXP_INTC_CLR_EN            ((reg32 *) isrXP__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrXP interrupt state to pending. */
#define isrXP_INTC_SET_PD            ((reg32 *) isrXP__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrXP interrupt. */
#define isrXP_INTC_CLR_PD            ((reg32 *) isrXP__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrXP_H */


/* [] END OF FILE */
