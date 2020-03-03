/*
 * File:   main.c
 * Author: dell
 *
 * Created on March 2, 2020, 8:56 PM
 */


#include <xc.h>
#include"config.h"

#define _XTAL_FREQ 8000000


int cont = 0;

void main() {
    
    ADCON1bits.PCFG = 0xF;
    TRISAbits.RA0 = 0;
    OSCCON = 0x72;
    Timer0_Init();
   if (cont <= 1000){
       PORTAbits.RA0 = 0;
   } 
    

    
}


void __interrupt(high_priority) interruptRB(void){

if(TMR0IF){
    
    if((cont>=100)&&(cont>=200))
        TMR0 = 0xF63B;      // 10mS every overflow
        TMR0IF = 0;         // 
        PORTAbits.RA0 = 1;

}
}
