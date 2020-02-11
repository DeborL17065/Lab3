/*
 * File:   main.c
 * Author: debor
 *
 * Created on February 5, 2020, 1:01 AM
 */
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

 
#define _XTAL_FREQ   8000000
#include <xc.h>
#include <pic16F887.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LCD.h"
#include "ACD.h"
#include "EUSART.h"


void init(void);
void Contador(void);


uint8_t CONT1 =0;

void main(void) {
    init();
    _RX_TX();
    LCD_INIT();
    while(1){
        CONF_ADC();
//        DEC_INC = RCREG;
//        Contador();
//        itoa(S3,CONT1,10);
//        LCD_XY(1,12);
//        LCD_Cadena(S3);
        
        
       
    }
    
    return;
}





void Contador(void){
    
    if (DEC_INC == '+'){ 
        CONT1++ ;      //se incrementa el contador
    }    
    
    if (DEC_INC == '-'){ 
        CONT1-- ;   //se decrementa el contador  
    } 

}


void init(void) { 
    TRISA =0b00000011; // los primeros 2 bits como entradas
    TRISD =0b00000000; //se define el puerto D como salidas
    TRISCbits.TRISC6 =0;
    TRISCbits.TRISC7 =1;
    PORTC =0;
    PORTD =0;          //se limpia el puerto D
    PORTA =0;          //se limpia el puerto A
    ANSELH =0;
    ANSELbits.ANS0 =1; //RA0 ANALÛGICO
    ANSELbits.ANS1 =1; //RA1 ANALÛGICO
    ///oscilador
    OSCCONbits.IRCF0 = 1;
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF2 = 1; 
   
}