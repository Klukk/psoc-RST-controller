/*******************************************************************************
* File Name: isrYL.h
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
#if !defined(CY_ISR_isrYL_H)
#define CY_ISR_isrYL_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrYL_Start(void);
void isrYL_StartEx(cyisraddress address);
void isrYL_Stop(void);

CY_ISR_PROTO(isrYL_Interrupt);

void isrYL_SetVector(cyisraddress address);
cyisraddress isrYL_GetVector(void);

void isrYL_SetPriority(uint8 priority);
uint8 isrYL_GetPriority(void);

void isrYL_Enable(void);
uint8 isrYL_GetState(void);
void isrYL_Disable(void);

void isrYL_SetPending(void);
void isrYL_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrYL ISR. */
#define isrYL_INTC_VECTOR            ((reg32 *) isrYL__INTC_VECT)

/* Address of the isrYL ISR priority. */
#define isrYL_INTC_PRIOR             ((reg8 *) isrYL__INTC_PRIOR_REG)

/* Priority of the isrYL interrupt. */
#define isrYL_INTC_PRIOR_NUMBER      isrYL__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrYL interrupt. */
#define isrYL_INTC_SET_EN            ((reg32 *) isrYL__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrYL interrupt. */
#define isrYL_INTC_CLR_EN            ((reg32 *) isrYL__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrYL interrupt state to pending. */
#define isrYL_INTC_SET_PD            ((reg32 *) isrYL__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrYL interrupt. */
#define isrYL_INTC_CLR_PD            ((reg32 *) isrYL__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrYL_H */


/* [] END OF FILE */
