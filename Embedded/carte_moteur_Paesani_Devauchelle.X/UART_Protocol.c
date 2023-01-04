#include <xc.h>
#include "UART_Protocol.h"
#include "CB_TX1.h"
#include "main.h"

extern unsigned char stateRobot;
unsigned char autoControlActivated;

unsigned char UartCalculateChecksum(int msgFunction, int msgPayloadLength, unsigned char* msgPayload) {
    //Fonction prenant entree la trame et sa longueur pour calculer le checksum
    unsigned char checksum = 0x00;
    checksum ^= 0xFE;
    checksum ^= (unsigned char) (msgFunction >> 8);
    checksum ^= (unsigned char) (msgFunction >> 0);
    checksum ^= (unsigned char) (msgPayloadLength >> 8);
    checksum ^= (unsigned char) (msgPayloadLength >> 0);

    for (int i = 0; i < msgPayloadLength; i++) {
        checksum ^= msgPayload[i];
    }
    return checksum;
}

void UartEncodeAndSendMessage(int msgFunction, int msgPayloadLength, unsigned char* msgPayload) {
    unsigned char message[msgPayloadLength + 6];
    int pos = 0;
    message[pos++] = 0xFE;
    message[pos++] = (unsigned char) (msgFunction >> 8);
    message[pos++] = (unsigned char) (msgFunction >> 0);
    message[pos++] = (unsigned char) (msgPayloadLength >> 8);
    message[pos++] = (unsigned char) (msgPayloadLength >> 0);

    for (int i = 0; i < msgPayloadLength; i++) {
        message[pos++] = msgPayload[i];
    }
    message[pos] = UartCalculateChecksum(msgFunction, msgPayloadLength, msgPayload);
    SendMessage(message, msgPayloadLength + 6);
}
int msgDecodedFunction = 0;
int msgDecodedPayloadLength = 0;
unsigned char msgDecodedPayload[128];
int msgDecodedPayloadIndex = 0;
int rcvState = 0;

void UartDecodeMessage(unsigned char c) {
    {
        switch (rcvState) {
            case WAITING:

                if (c == 0xFE) {
                    rcvState = FUNCTIONMSB;
                }
                break;

            case FUNCTIONMSB:

                msgDecodedFunction = c << 8;
                rcvState = FUNCTIONLSB;

                break;

            case FUNCTIONLSB:

                msgDecodedFunction = c << 0;
                rcvState = PAYLOADLENGTHMSB;

                break;

            case PAYLOADLENGTHMSB:

                msgDecodedPayloadLength = c << 8;
                rcvState = PAYLOADLENGTHLSB;

                break;

            case PAYLOADLENGTHLSB:

                msgDecodedPayloadLength = c << 0;
                msgDecodedPayloadIndex = 0;
                rcvState = PAYLOAD;

                break;

            case PAYLOAD:

                if (msgDecodedPayloadIndex < msgDecodedPayloadLength) {
                    msgDecodedPayload[msgDecodedPayloadIndex] = c;
                    msgDecodedPayloadIndex++;

                    if (msgDecodedPayloadIndex == msgDecodedPayloadLength) {
                        rcvState = CHECKSUM;
                    }
                }


                break;

            case CHECKSUM:

                if (UartCalculateChecksum(msgDecodedFunction, msgDecodedPayloadLength, msgDecodedPayload) == c) {
                    UartProcessDecodedMessage(msgDecodedFunction, msgDecodedPayloadLength, msgDecodedPayload);
                }
                rcvState = WAITING;
                break;

            default:
                rcvState = WAITING;
                break;
        }
    }
}

void UartProcessDecodedMessage(int function, int payloadLength, unsigned char* payload) {
    switch (function) {
        case SET_ROBOT_STATE:
            SetRobotState(payload[0]);

            break;
        case SET_ROBOT_MANUAL_CONTROL: 
            SetRobotAutoControlState(payload[0]);
            break;

        default:
            break;
    }
}
//*************************************************************************/
//Fonctions correspondant aux messages
//*************************************************************************/


void SetRobotState(unsigned char state) {
    stateRobot = state;
}
void SetRobotAutoControlState(unsigned char state) {
    autoControlActivated = state;
    if(autoControlActivated == 0)
        stateRobot = STATE_ARRET;
    else
        stateRobot = STATE_ATTENTE;
}