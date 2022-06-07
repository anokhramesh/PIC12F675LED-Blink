/*
 * pic12F675 blink
 * Author: Anokhramesh
 * anokhramesh@gmail.com
 * Created on 07/june/ 2022, 11:55 AM
 */


// PIC12F675 Configuration Bit Settings

// 'C' source line configuration statements

// CONFIG
#pragma config FOSC = INTRCCLK  // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // GP3/MCLR pin function select (GP3/MCLR pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// #pragma configuration statements should precede project file includes.

#define _XTAL_FREQ 4000000// set crystal frequency 4MegaHz
#include <xc.h>

 void delay_ms(unsigned int milliseconds)
 {
   while(milliseconds > 0)
   {
       __delay_ms(1);
      milliseconds--;
    }
 }
 
void blink(unsigned int i){
    GPIO0=1;
    delay_ms(i);
    GPIO0=0;
    delay_ms(i);
}

void main(void) {
    TRISIO0=0;
    while(1){
        for(int i=0;i<=500;i+=100)
            blink(i);
        for(int i=500;i>=0;i-=100)
            blink(i);
    }
    return;
}
