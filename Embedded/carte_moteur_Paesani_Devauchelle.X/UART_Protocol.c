#include <xc.h>
#include "UART_Protocol.h"
#include "CB_TX1.h"
unsigned char UartCalculateChecksum(int msgFunction,int msgPayloadLength, unsigned char* msgPayload)
{
//Fonction prenant entree la trame et sa longueur pour calculer le checksum
            unsigned char checksum = 0x00;
            checksum ^= 0xFE;
            checksum ^= (unsigned char)(msgFunction >>8);
            checksum ^= (unsigned char)(msgFunction >> 0);
            checksum ^= (unsigned char)(msgPayloadLength >> 8);
            checksum ^= (unsigned char)(msgPayloadLength >> 0);

            for(int i=0; i<msgPayloadLength;i++)
            {
                checksum ^= msgPayload[i];
            }
            return checksum;
}
void UartEncodeAndSendMessage(int msgFunction,int msgPayloadLength, unsigned char* msgPayload)
{
            unsigned char message[msgPayloadLength + 6];
            int pos = 0;
            message[pos++] = 0xFE;
            message[pos++] = ( unsigned char)(msgFunction >> 8);
            message[pos++] = ( unsigned char)(msgFunction >> 0);
            message[pos++] = ( unsigned char)(msgPayloadLength >> 8);
            message[pos++] = ( unsigned char)(msgPayloadLength >> 0);

            for(int i=0; i<msgPayloadLength; i++)
            {
                message[pos++]= msgPayload[i];
            }
            message[pos] = UartCalculateChecksum(msgFunction, msgPayloadLength,msgPayload);
            SendMessage(message, msgPayloadLength+6);
}
int msgDecodedFunction = 0;
int msgDecodedPayloadLength = 0;
unsigned char msgDecodedPayload[128];
int msgDecodedPayloadIndex = 0;
//void UartDecodeMessage(unsigned char c)
//{
////Fonction prenant en entree un octet et servant a reconstituer les trames
//...
//}
//void UartProcessDecodedMessage(int function,int payloadLength, unsigned char* payload)
//{
////Fonction appelee apres le decodage pour executer l?action
////correspondant au message recu
//...
//}
//*************************************************************************/
//Fonctions correspondant aux messages
//*************************************************************************/