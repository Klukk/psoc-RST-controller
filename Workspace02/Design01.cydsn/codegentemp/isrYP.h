/*******************************************************************************
* File Name: isrYP.h
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
#if !defined(CY_ISR_isrYP_H)
#define CY_ISR_isrYP_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrYP_Start(void);
void isrYP_StartEx(cyisraddress address);
void isrYP_Stop(void);

CY_ISR_PROTO(isrYP_Interrupt);

void isrYP_SetVector(cyisraddress address);
cyisraddress isrYP_GetVector(void);

void isrYP_SetPriority(uint8 priority);
uint8 isrYP_GetPriority(void);

void isrYP_Enable(void);
uint8 isrYP_GetState(void);
void isrYP_Disable(void);

void isrYP_SetPending(void);
void isrYP_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrYP ISR. */
#define isrYP_INTC_VECTOR            ((reg32 *) isrYP__INTC_VECT)

/* Address of the isrYP ISR priority. */
#define isrYP_INTC_PRIOR             ((reg8 *) isrYP__INTC_PRIOR_REG)

/* Priority of the isrYP interrupt. */
#define isrYP_INTC_PRIOR_NUMBER      isrYP__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrYP interrupt. */
#define isrYP_INTC_SET_EN            ((reg32 *) isrYP__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrYP interrupt. */
#define isrYP_INTC_CLR_EN            ((reg32 *) isrYP__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrYP interrupt state to pending. */
#define isrYP_INTC_SET_PD            ((reg32 *) isrYP__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrYP interrupt. */
#define isrYP_INTC_CLR_PD            ((reg32 *) isrYP__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrYP_H */


/* [] END OF FILE */
