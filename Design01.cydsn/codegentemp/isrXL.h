/*******************************************************************************
* File Name: isrXL.h
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
#if !defined(CY_ISR_isrXL_H)
#define CY_ISR_isrXL_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrXL_Start(void);
void isrXL_StartEx(cyisraddress address);
void isrXL_Stop(void);

CY_ISR_PROTO(isrXL_Interrupt);

void isrXL_SetVector(cyisraddress address);
cyisraddress isrXL_GetVector(void);

void isrXL_SetPriority(uint8 priority);
uint8 isrXL_GetPriority(void);

void isrXL_Enable(void);
uint8 isrXL_GetState(void);
void isrXL_Disable(void);

void isrXL_SetPending(void);
void isrXL_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrXL ISR. */
#define isrXL_INTC_VECTOR            ((reg32 *) isrXL__INTC_VECT)

/* Address of the isrXL ISR priority. */
#define isrXL_INTC_PRIOR             ((reg8 *) isrXL__INTC_PRIOR_REG)

/* Priority of the isrXL interrupt. */
#define isrXL_INTC_PRIOR_NUMBER      isrXL__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrXL interrupt. */
#define isrXL_INTC_SET_EN            ((reg32 *) isrXL__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrXL interrupt. */
#define isrXL_INTC_CLR_EN            ((reg32 *) isrXL__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrXL interrupt state to pending. */
#define isrXL_INTC_SET_PD            ((reg32 *) isrXL__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrXL interrupt. */
#define isrXL_INTC_CLR_PD            ((reg32 *) isrXL__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrXL_H */


/* [] END OF FILE */
