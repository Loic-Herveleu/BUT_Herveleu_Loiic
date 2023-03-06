#include <xc.h>
#include "UART_Protocol.h"
#include "CB_TX1.h"
#include "main.h"
#include "Utilities.h"
#include "Robot.h"
#include "asservissement.h"

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
            
        case ASSERVISSEMENT:
        {
            unsigned char tabkp[4],tabki[4],tabkd[4],tabpropmax[4],tabintegmax[4],tabderivemax[4], tabconsigne[4];
            
            tabkp[0]=payload[1];
            tabkp[1]=payload[2];
            tabkp[2]=payload[3];
            tabkp[3]=payload[4];
            
            tabki[0]=payload[5];
            tabki[1]=payload[6];
            tabki[2]=payload[7];
            tabki[3]=payload[8];
              
            tabkd[0]=payload[9];
            tabkd[1]=payload[10];
            tabkd[2]=payload[11];
            tabkd[3]=payload[12];
            
            tabpropmax[0]=payload[13];
            tabpropmax[1]=payload[14];
            tabpropmax[2]=payload[15];
            tabpropmax[3]=payload[16];
            
            tabintegmax[0]=payload[17];
            tabintegmax[1]=payload[18];
            tabintegmax[2]=payload[19];
            tabintegmax[3]=payload[20];
            
            tabderivemax[0]=payload[21];
            tabderivemax[1]=payload[22];
            tabderivemax[2]=payload[23];
            tabderivemax[3]=payload[24];
            
            tabconsigne[0]=payload[25];
            tabconsigne[1]=payload[26];
            tabconsigne[2]=payload[27];
            tabconsigne[3]=payload[28];
            
            float Kp=getFloat(tabkp,0);
            float Ki=getFloat(tabki,0);
            float Kd=getFloat(tabkd,0);
            float propmax=getFloat(tabpropmax,0);
            float integmax=getFloat(tabintegmax,0);
            float derivemax=getFloat(tabderivemax,0);
            float consigne=getFloat(tabconsigne,0);
            
            if(payload[0]==0)
            {
            SetupPidAsservissement(&robotState.PidX,  Kp, Ki, Kd, propmax, integmax, derivemax, consigne);
            SendPidAsservissement(&robotState.PidX);
            }
            else if(payload[0]==1)
            {
            SetupPidAsservissement(&robotState.PidTheta, Kp, Ki, Kd, propmax, integmax, derivemax, consigne);
            SendPidAsservissement(&robotState.PidTheta);
            }
        }
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