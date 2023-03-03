#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "asservissement.h"

double proportionelleMax, integralMax, deriveeMax;
#define  FREQ_ECH_QEI 250

void SetupPidAsservissement(volatile PidCorrector* PidCorr, double Kp, double Ki, double Kd, double proportionelleMax, double integralMax, double deriveeMax )
{
    PidCorr->Kp = Kp;
    PidCorr->erreurProportionelleMax = proportionelleMax; //On limite la correction due au Kp
    PidCorr->Ki = Ki;
    PidCorr->erreurIntegraleMax = integralMax; //On limite la correction due au Ki
    PidCorr->Kd = Kd;
    PidCorr->erreurDeriveeMax = deriveeMax;
}
void sendPidAsservissement(volatile PidCorrector* PidCorr)
{
double kp, ki, kd,proportionnelleMax, integralMax, deriveeMax;
unsigned char message[25];
    kp=PidCorr->Kp;
    proportionelleMax=PidCorr->erreurProportionelleMax; //On limite la correction due au Kp
    ki=PidCorr->Ki;
    integralMax=PidCorr->erreurIntegraleMax; //On limite la correction due au Ki
    kd=PidCorr->Kd;
    deriveeMax=PidCorr->erreurDeriveeMax;
    
    if(PidCorr==PidX)
    {
        message[0]=0;
    }
    else
    {
        message[0]=1;
    }
    
    getByteFromFloat(message, 1, kp);
    getByteFromFloat(message, 5, ki);
    getByteFromFloat(message, 9, kd);
    getByteFromFloat(message, 13, erreurProportionelleMax);
    getByteFromFloat(message, 17, erreurIntegraleMax);
    getByteFromFloat(message, 21, erreurDeriveeMax);
    
    UartEncodeAndSendMessage(0x0063,25, message);
}

//double Correcteur(volatile PidCorrector*PidCorr, double erreur)
//{
//PidCorr->erreur = erreur;
//double erreurProportionnelle = LimitToInterval(proportionelleMax);
//PidCorr->corrP = ...;
//PidCorr->erreurIntegrale += ...;
//PidCorr->erreurIntegrale = LimitToInterval(...);
//PidCorr->corrI = ...;
//double erreurDerivee = (erreur - PidCorr->epsilon_1)*FREQ_ECH_QEI;
//double deriveeBornee = LimitToInterval(erreurDerivee, -PidCorr->erreurDeriveeMax/PidCorr->Kd, PidCorr->epsilon_1 = erreur);
//PidCorr->corrD = deriveeBornee * PidCorr->Kd;
//
//return PidCorr->corrP+PidCorr->corrI+PidCorr->corrD;
//}

//void UpdateAsservissement()
//{
//robotState.PidX.erreur = ...;
//robotState.PidTheta.erreur = ...;
//robotState.xCorrectionVitessePourcent =
//Correcteur(&robotState.PidX, robotState.PidX.erreur);
//robotState.thetaCorrectionVitessePourcent = ...;
//PWMSetSpeedConsignePolaire(robotState.xCorrectionVitessePourcent,
//robotState.thetaCorrectionVitessePourcent);
//}
