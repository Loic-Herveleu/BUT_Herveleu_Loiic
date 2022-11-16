/* 
 * File:   UART.h
 * Author: TABLE 6
 *
 * Created on 10 novembre 2022, 12:20
 */

#ifndef UART_H
#define	UART_H

void InitUART(void);
void SendMessageDirect(unsigned char* message, int length);

#endif	/* UART_H */

