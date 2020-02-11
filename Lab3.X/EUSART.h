/* 
 * File:   EUSART.h
 * Author: debor
 *
 * Created on February 6, 2020, 11:58 PM
 */

#ifndef EUSART_H
#define	EUSART_H

char DEC_INC;


void _RX_TX (void);
//void SerialSendChar (char CARACTER);
void SerialSendString(unsigned char *txbuffer);


#endif	/* EUSART_H */

