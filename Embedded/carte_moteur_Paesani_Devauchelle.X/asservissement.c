#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "asservissement.h"
#include "Robot.h"
#include "Utilities.h"
#include "UART_Protocol.h"
#include "ToolBox.h"

double proportionelleMax, integralMax, deriveeMax;
#define  FREQ_ECH_QEI 250

void SetupPidAsservissement(volatile PidCorrector* PidCorr, double Kp, double Ki, double Kd, double proportionelleMax, double integralMax, double deriveeMax, double consigne) {
    PidCorr->Kp = Kp;
    PidCorr->erreurProportionelleMax = proportionelleMax; //On limite la correction due au Kp
    PidCorr->Ki = Ki;
    PidCorr->erreurIntegraleMax = integralMax; //On limite la correction due au Ki
    PidCorr->Kd = Kd;
    PidCorr->erreurDeriveeMax = deriveeMax;
    PidCorr->Consigne = consigne;
}

void SendPidAsservissement(volatile PidCorrector* PidCorr) {
    unsigned char message[29];

    if (PidCorr == &robotState.PidX) {
        message[0] = 0;
    } else if (PidCorr == &robotState.PidTheta) {
        message[0] = 1;
    }

    getBytesFromFloat(message, 1, PidCorr->Kp);
    getBytesFromFloat(message, 5, PidCorr->Ki);
    getBytesFromFloat(message, 9, PidCorr->Kd);
    getBytesFromFloat(message, 13, PidCorr->erreurProportionelleMax);
    getBytesFromFloat(message, 17, PidCorr->erreurIntegraleMax);
    getBytesFromFloat(message, 21, PidCorr->erreurDeriveeMax);
    getBytesFromFloat(message, 25, PidCorr->Consigne);


    UartEncodeAndSendMessage(0x0063, 29, message);


}

double Correcteur(volatile PidCorrector*PidCorr, double erreur) {
    PidCorr->erreur = erreur;

    double erreurProportionnelle = erreur;
    erreurProportionnelle = LimitToInterval(erreurProportionnelle, -PidCorr->erreurProportionelleMax / PidCorr->Kp, PidCorr->erreurProportionelleMax / PidCorr->Kp);
    PidCorr->corrP = erreurProportionnelle * PidCorr->Kp;

    PidCorr->erreurIntegrale = PidCorr->erreurIntegrale + erreur / (float) (FREQ_ECH_QEI);
    PidCorr->erreurIntegrale = LimitToInterval(PidCorr->erreurIntegrale, -PidCorr->erreurIntegraleMax / PidCorr->Ki, PidCorr->erreurIntegraleMax / PidCorr->Ki);
    PidCorr->corrI = (PidCorr->erreurIntegrale) * PidCorr->Ki;

    double erreurDerivee = (erreur - PidCorr->epsilon_1)*(float) (FREQ_ECH_QEI);
    double deriveeBornee = LimitToInterval(erreurDerivee, -PidCorr->erreurDeriveeMax / PidCorr->Kd, PidCorr->erreurDeriveeMax / PidCorr->Kd);
    PidCorr->corrD = deriveeBornee * PidCorr->Kd;
    PidCorr->epsilon_1 = erreur;
    return PidCorr->corrP + PidCorr->corrI + PidCorr->corrD;
}

void UpdateAsservissement() {
    robotState.PidX.erreur = robotState.PidX.Consigne - robotState.vitesseLineaireFromOdometry;
    robotState.PidTheta.erreur = robotState.PidX.Consigne - robotState.vitesseAngulaireFromOdometry;

    robotState.xCorrectionVitessePourcent = Correcteur(&robotState.PidX, robotState.PidX.erreur);
    robotState.thetaCorrectionVitessePourcent = Correcteur(&robotState.PidTheta, robotState.PidTheta.erreur);

    //PWMSetSpeedConsignePolaire(robotState.xCorrectionVitessePourcent,robotState.thetaCorrectionVitessePourcent);
}

void SendPidVariablesAsservissement() {
    unsigned char variablesAsserv[32];

    getBytesFromFloat(variablesAsserv, 0, robotState.PidX.erreur);
    getBytesFromFloat(variablesAsserv, 4, robotState.PidTheta.erreur);
    getBytesFromFloat(variablesAsserv, 8, robotState.PidX.corrP);
    getBytesFromFloat(variablesAsserv, 12, robotState.PidTheta.corrP);
    getBytesFromFloat(variablesAsserv, 16, robotState.PidX.corrI);
    getBytesFromFloat(variablesAsserv, 20, robotState.PidTheta.corrI);
    getBytesFromFloat(variablesAsserv, 24, robotState.PidX.corrD);
    getBytesFromFloat(variablesAsserv, 28, robotState.PidTheta.corrD);

    UartEncodeAndSendMessage(0x0064, 33, variablesAsserv);
}