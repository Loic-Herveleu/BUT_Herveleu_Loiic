/* 
 * File:   UART_Protocol.h
 * Author: TABLE 6
 *
 * Created on 12 d�cembre 2022, 18:05
 */

#ifndef UART_PROTOCOL_H
#define	UART_PROTOCOL_H

unsigned char UartCalculateChecksum(int msgFunction,int msgPayloadLength, unsigned char* msgPayload);
void UartEncodeAndSendMessage(int msgFunction,int msgPayloadLength, unsigned char* msgPayload);
void UartDecodeMessage(unsigned char c);
void UartProcessDecodedMessage(int function,int payloadLength, unsigned char* payload);


#endif	/* UART_PROTOCOL_H */

