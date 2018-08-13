 /* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * =======================================
*/
#include "project.h"
#include <stdlib.h>


char datorecibido[10];
int counta=0,countb=0,pwmx=0,pwmy=0,i=0,x=0,MXV=0,MYV=0;
char datoenviado[20];
char MX[2];
char DX;
char MY[2];
char DY;


CY_ISR(InterruptRX)
{
datorecibido[i]=UART_GetChar();
i++;
if(i>=10){i=0;x=0;}}



CY_ISR(InterruptXP)
{
counta++;
}
CY_ISR(InterruptXL)
{
counta--;
}
CY_ISR(InterruptYP)
{
countb++;
}
CY_ISR(InterruptYL)
{
countb--;
}

void UART_writeint(val)
{
char buff[33];

itoa(val, buff,  10);
UART_PutString(buff);
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    PWM_Start();
    Clock_1_Start();
    isrRx_StartEx(InterruptRX);
    isrXP_StartEx(InterruptXP);
    isrXL_StartEx(InterruptXL);
    isrYP_StartEx(InterruptYP);
    isrYL_StartEx(InterruptYL);
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
     if(datorecibido[i]=='x'){i=0;x=1;}
MX[0]=datorecibido[2];
MX[1]=datorecibido[3];
MX[2]=datorecibido[4];
MXV=atoi(MX);

MY[0]=datorecibido[7];
MY[1]=datorecibido[8];
MY[2]=datorecibido[9];
MYV=atoi(MY);

    UART_PutChar('  ');
    UART_writeint(counta);
    UART_PutChar(','); 
    UART_writeint(countb);
    UART_PutChar('\n'); 
    UART_PutChar(0x0D);
    if(MXV<=0){MXV=0;}
    if(MYV<=0){MYV=0;}
    if(MXV>=255){MXV=255;}
    if(MYV>=255){MYV=255;}
    PWM_WriteCompare1(MXV); 
    PWM_WriteCompare2(MYV); 
  
    if(datorecibido[6]=='-'){
    A1_Write(1);  
    B1_Write(0); 
    }else{
    A1_Write(0); 
    B1_Write(1);}
    if(datorecibido[1]=='-'){
    A2_Write(1); 
    B2_Write(0); 
    }else{
    A2_Write(0); 
    B2_Write(1);}
    }
}

/* [] END OF FILE */
