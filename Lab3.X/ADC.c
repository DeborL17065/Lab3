/*
 * File:   ADC.c
 * Author: debor
 *
 * Created on February 6, 2020, 11:23 PM
 */


#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ACD.h"
#include "LCD.h"
#include "EUSART.h"



void CONF_ADC(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    ADCON0 = 0b01000001; //AN0
    ADCON1 = 0b10000000;
    ADCON0bits.GO_DONE =1; //se inicia la conversión
    while(ADCON0bits.GO_DONE ==1); 
    SENSOR1 = ADRESH;
    SENSOR1 = SENSOR1<<8;
    SENSOR1 |= ADRESL;
    V_SENSOR1 =(SENSOR1*5.0)/1022; //se pasa de 0-5
    sprintf(S1,"%3.2f",V_SENSOR1); //se pasa de float a char
    strcpy(val1,"SENSOR1:"); //se coloca el caracter dentro del char
    strcat(val1,S1); //se concatenan ambos chars
    SerialSendString(val1); //DATOS A ENVIARA AL ARDUINO
  
    Lcd_Clear();
    LCD_XY(0,2);
    LCD_Cadena("S1:  S2:  S3:"); 
    LCD_XY(1,2);
    LCD_Cadena(S1);//manda el dato a la LCD

    ADCON0 = 0b01000101; //AN1
    ADCON1 = 0b10000000;
    ADCON0bits.GO_DONE =1; //se inicia la conversión
    while(ADCON0bits.GO_DONE ==1); 
    SENSOR2 = ADRESH;
    SENSOR2 = SENSOR2<<8;
    SENSOR2 |= ADRESL;
    V_SENSOR2 =(SENSOR2*5.0)/1022; //se pasa de 0-5
    sprintf(S2,"%3.2f",V_SENSOR2); //se pasa de float a char
    strcpy(val2,"SENSOR2:"); //se coloca el caracter dentro del char
    strcat(val2,S2);         //se concatenan ambos chars
    SerialSendString(val2); //DATOS A ENVIARA AL ARDUINO
    LCD_XY(1,7);
    LCD_Cadena(S2); //manda el dato a la LCD
    
}








