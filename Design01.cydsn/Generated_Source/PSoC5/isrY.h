/*******************************************************************************
* File Name: isrY.h
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
#if !defined(CY_ISR_isrY_H)
#define CY_ISR_isrY_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrY_Start(void);
void isrY_StartEx(cyisraddress address);
void isrY_Stop(void);

CY_ISR_PROTO(isrY_Interrupt);

void isrY_SetVector(cyisraddress address);
cyisraddress isrY_GetVector(void);

void isrY_SetPriority(uint8 priority);
uint8 isrY_GetPriority(void);

void isrY_Enable(void);
uint8 isrY_GetState(void);
void isrY_Disable(void);

void isrY_SetPending(void);
void isrY_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrY ISR. */
#define isrY_INTC_VECTOR            ((reg32 *) isrY__INTC_VECT)

/* Address of the isrY ISR priority. */
#define isrY_INTC_PRIOR             ((reg8 *) isrY__INTC_PRIOR_REG)

/* Priority of the isrY interrupt. */
#define isrY_INTC_PRIOR_NUMBER      isrY__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrY interrupt. */
#define isrY_INTC_SET_EN            ((reg32 *) isrY__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrY interrupt. */
#define isrY_INTC_CLR_EN            ((reg32 *) isrY__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrY interrupt state to pending. */
#define isrY_INTC_SET_PD            ((reg32 *) isrY__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrY interrupt. */
#define isrY_INTC_CLR_PD            ((reg32 *) isrY__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrY_H */


/* [] END OF FILE */
