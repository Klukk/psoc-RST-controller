/*******************************************************************************
* File Name: countdwn.h
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
#if !defined(CY_ISR_countdwn_H)
#define CY_ISR_countdwn_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void countdwn_Start(void);
void countdwn_StartEx(cyisraddress address);
void countdwn_Stop(void);

CY_ISR_PROTO(countdwn_Interrupt);

void countdwn_SetVector(cyisraddress address);
cyisraddress countdwn_GetVector(void);

void countdwn_SetPriority(uint8 priority);
uint8 countdwn_GetPriority(void);

void countdwn_Enable(void);
uint8 countdwn_GetState(void);
void countdwn_Disable(void);

void countdwn_SetPending(void);
void countdwn_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the countdwn ISR. */
#define countdwn_INTC_VECTOR            ((reg32 *) countdwn__INTC_VECT)

/* Address of the countdwn ISR priority. */
#define countdwn_INTC_PRIOR             ((reg8 *) countdwn__INTC_PRIOR_REG)

/* Priority of the countdwn interrupt. */
#define countdwn_INTC_PRIOR_NUMBER      countdwn__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable countdwn interrupt. */
#define countdwn_INTC_SET_EN            ((reg32 *) countdwn__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the countdwn interrupt. */
#define countdwn_INTC_CLR_EN            ((reg32 *) countdwn__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the countdwn interrupt state to pending. */
#define countdwn_INTC_SET_PD            ((reg32 *) countdwn__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the countdwn interrupt. */
#define countdwn_INTC_CLR_PD            ((reg32 *) countdwn__INTC_CLR_PD_REG)


#endif /* CY_ISR_countdwn_H */


/* [] END OF FILE */
