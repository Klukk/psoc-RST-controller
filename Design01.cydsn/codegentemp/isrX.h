/*******************************************************************************
* File Name: isrX.h
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
#if !defined(CY_ISR_isrX_H)
#define CY_ISR_isrX_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrX_Start(void);
void isrX_StartEx(cyisraddress address);
void isrX_Stop(void);

CY_ISR_PROTO(isrX_Interrupt);

void isrX_SetVector(cyisraddress address);
cyisraddress isrX_GetVector(void);

void isrX_SetPriority(uint8 priority);
uint8 isrX_GetPriority(void);

void isrX_Enable(void);
uint8 isrX_GetState(void);
void isrX_Disable(void);

void isrX_SetPending(void);
void isrX_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrX ISR. */
#define isrX_INTC_VECTOR            ((reg32 *) isrX__INTC_VECT)

/* Address of the isrX ISR priority. */
#define isrX_INTC_PRIOR             ((reg8 *) isrX__INTC_PRIOR_REG)

/* Priority of the isrX interrupt. */
#define isrX_INTC_PRIOR_NUMBER      isrX__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrX interrupt. */
#define isrX_INTC_SET_EN            ((reg32 *) isrX__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrX interrupt. */
#define isrX_INTC_CLR_EN            ((reg32 *) isrX__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrX interrupt state to pending. */
#define isrX_INTC_SET_PD            ((reg32 *) isrX__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrX interrupt. */
#define isrX_INTC_CLR_PD            ((reg32 *) isrX__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrX_H */


/* [] END OF FILE */
