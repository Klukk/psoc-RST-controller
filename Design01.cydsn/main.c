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
int counta=0,countb=0,pwmx=0,pwmy=0,i=0,x=0,MXV=0,MYV=0,MXV0=0,MYV0=0,MXV00=0,MYV00=0,retx,rety;
int KPX=0,KIX=0,rfaa,rfa,raa,rf,xxx;
double ssx=0,ssax=0,ssaax=0,sex=0,seax=0,seaax=0,refsx=0,refsax=0,refsaax=0,refex=0,refeax=0,refeaax=0;
double retsx=0,retsax=0,retsaax=0,retex=0,reteax=0,reteaax=0;
double ssy=0,ssay=0,ssaay=0,sey=0,seay=0,seaay=0,refsy=0,refsay=0,refsaay=0,refey=0,refeay=0,refeaay=0;
double retsy=0,retsay=0,retsaay=0,retey=0,reteay=0,reteaay=0;
char datoenviado[20];
char MX[2],MY[2],DX,DY;


CY_ISR(InterruptRX)
{datorecibido[i]=UART_GetChar();
i++;
if(i>=10){i=0;x=0;}}

CY_ISR(InterruptXL)
{counta++;}

CY_ISR(InterruptXP)
{counta--;}

CY_ISR(InterruptYL)
{countb++;}

CY_ISR(InterruptYP)
{countb--;}
CY_ISR(InterruptX)
{countb=0;

}
CY_ISR(InterruptY)
{counta=0;
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
    isrX_StartEx(InterruptX);
    isrY_StartEx(InterruptY);
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
     if(datorecibido[i]=='x'){i=0;x=1;}
        MX[0]=datorecibido[2];
        MX[1]=datorecibido[3];
        MX[2]=datorecibido[4];
        MXV0=atoi(MX);

        if(datorecibido[1]=='-')
        {MXV0=0-MXV0;}
        else{MXV0=MXV0;}
        
        MY[0]=datorecibido[7];
        MY[1]=datorecibido[8];
        MY[2]=datorecibido[9];
        MYV0=atoi(MY);
       
        if(datorecibido[6]=='-')
        {MYV0=0-MYV0;}
        else{MYV0=MYV0;}
       
        //////////////////////////////////////////////////////////////////////////////
        /*Control Motor X*/
        /////////////////////////////////////////////////////////////////////////////
        
        refex=MXV0;
        sex=counta;
        
        //       1.8416   -2.1619    0.4164

        retex=refex-sex;
        retsx = retsax+1.8416*retex-2.1619*reteax+0.4164*reteaax;
        MXV=retsx;
        
        
        seax=sex;
        seaax=seax;
        reteax=retex;
        reteaax=reteax;
        retsax=retsx;
        retsaax=retsax;
        
        
        //////////////////////////////////////////////////////////////////////////////
        /*Control Motor Y*/
        /////////////////////////////////////////////////////////////////////////////
        
        refey=MYV0;
        sey=countb;
        
        //       2.2099   -2.5943    0.4996
        retey=refey-sey;
        retsy = retsay+1.2099*retey-1.5943*reteay+0.4996*reteaay;
        MYV=retsy;
        seay=sey;
        seaay=seay;
        reteay=retey;
        reteaay=reteay;
        retsay=retsy;
        retsaay=retsay;
        
    
    
     
        
  /*  if(MXV<=-255){MXV=-255;}
    if(MYV<=-255){MYV=-255;}
    if(MXV>=255){MXV=255;}
    if(MYV>=255){MYV=255;}*/

 
    
    if(counta>0 && counta<=9){UART_PutChar('0');UART_PutChar('0');}
 if(counta>=10 && counta<=99){UART_PutChar('0');}
if(counta>=-9 && counta<0){UART_PutChar('0');UART_PutChar('0');}
 if(counta>=-99 && counta<=-10){UART_PutChar('0');}
   if(counta==0){UART_PutChar('0');UART_PutChar('0');UART_PutChar('0');} else{UART_writeint(counta);}
    
    UART_PutChar(',');  

       if(countb>0 && countb<=9){UART_PutChar('0');UART_PutChar('0');}
 if(countb>=10 && countb<=99){UART_PutChar('0');}
if(countb>=-9 && countb<0){UART_PutChar('0');UART_PutChar('0');}
 if(countb>=-99 && countb<=-10){UART_PutChar('0');}
   if(countb==0){UART_PutChar('0');UART_PutChar('0');UART_PutChar('0');} else{UART_writeint(countb);}
    
    
    UART_PutChar(','); 
 if(MXV>0 && MXV<=9){UART_PutChar('0');UART_PutChar('0');}
 if(MXV>=10 && MXV<=99){UART_PutChar('0');}
   if(MXV==0){UART_PutChar('0');UART_PutChar('0');UART_PutChar('0');} else{UART_writeint(MXV);}
    UART_PutChar(','); 
if(MYV>0 && MYV<=9){UART_PutChar('0');UART_PutChar('0');}
 if(MYV>=10 && MYV<=99){UART_PutChar('0');}
   if(MYV==0){UART_PutChar('0');UART_PutChar('0');UART_PutChar('0');} else{UART_writeint(MYV);}
  UART_PutChar(';');

    UART_PutChar('\n');
    UART_PutChar(0x0D);
    
    
    
    
    
    PWM_WriteCompare1(abs(MXV)); 
    PWM_WriteCompare2(abs(MYV)); 
    
    if(MYV<0){
    A1_Write(1);  
    B1_Write(0); 
    }else{
    A1_Write(0); 
    B1_Write(1);}
    
   
    if(MXV<0){
    A2_Write(1); 
    B2_Write(0); 
    }else{
    A2_Write(0); 
    B2_Write(1);}
    
    
    PWM_WriteCompare1(abs(MXV)); 
    PWM_WriteCompare2(abs(MYV));
    
    
    /*if(datorecibido[6]=='-'){
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
    B2_Write(1);}*/
    }
}

/* [] END OF FILE */
