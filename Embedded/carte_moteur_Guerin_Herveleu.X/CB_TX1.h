/* 
 * File:   CB_TX1.h
 * Author: TABLE 6
 *
 * Created on 22 novembre 2022, 09:55
 */

#ifndef CB_TX1_H
#define	CB_TX1_H

void SendMessage(unsigned char* message, int length);
void CB_TX1_Add(unsigned char value);
unsigned char CB_TX1_Get(void);
void SendOne();
unsigned char CB_TX1_IsTranmitting(void);
int CB_TX1_DataSize(void);
int CB_TX1_RemainingSize(void);

#endif	/* CB_TX1_H */

