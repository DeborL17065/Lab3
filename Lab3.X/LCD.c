/*
 * File:   LCD.c
 * Author: debor
 *
 * Created on February 5, 2020, 4:25 PM
 */
/* Se utilizó y se adaptaron las librerías de Ligo George 
 * de la página www.electrosome.com
 * Enlace: https://electrosome.com/lcd-pic-mplab-xc8/
*/

#include <xc.h>
#include "LCD.h"

void LCD_INIT (void){

    RW_T = 0;      //RW COMO SALIDA
    RS_T = 0;      //RS COMO SALIDA
    E_T = 0;       //E  COMO SALIDA
    
    RW = 0;        //Modo Escritura
    RS = 0;        //Modo Comandos
    E = 0;         //Deshabilita LCD
    
    LCD_COMANDO(0x00);
    __delay_ms(20);
    LCD_COMANDO(0x30);
    __delay_ms(5);
    LCD_COMANDO(0x30);
    __delay_ms(11);
    LCD_COMANDO(0x30);
    __delay_us(100);
    

    //8 bits mode
    LCD_COMANDO(0x38);
    __delay_us(100);
    LCD_COMANDO(0x08); //display off
    __delay_us(100);
    LCD_COMANDO(0x01); //clear display
    __delay_us(100);
    LCD_COMANDO(0x06); //Entry mode set
    __delay_us(100);
    LCD_COMANDO(0x0C); //display on
    __delay_us(100);
  //  LCD_COMANDO(0x06);

    return;


}

void LCD_COMANDO(char cmd){
    RW =0;            //Modo Escritura
    RS =0;            //Modo Comandos
    LCD_PORT =cmd;
    E =1;             //Habilita LCD
    __delay_ms(5);
    E =0;             //Deshabilita LCD
}

void Lcd_Clear(void)
{
	LCD_COMANDO(0);
	LCD_COMANDO(1);
}

void LCD_XY(char x,char y){
    if(x>0){
        LCD_COMANDO(0xC0+y);
    }
    else{
        LCD_COMANDO(0x80+y);
    }
}

void LCD_Cadena(char *data){
    int i;
	for(i=0;data[i]!='\0';i++)
	LCD_Data(data[i]);
}

void LCD_Data(char data){
    //__delay_us(100);
    LCD_PORT = 0;
    
    //Configuración 
    
    RW = 0;     //Modo Escritura
    RS = 1;     //Modo Caracter
    LCD_PORT = data;
    __delay_us(40);
    E = 1;      //Habilita LCD
    __delay_us(40);
    E = 0;      //Deshabilita LCD
    return;

}
