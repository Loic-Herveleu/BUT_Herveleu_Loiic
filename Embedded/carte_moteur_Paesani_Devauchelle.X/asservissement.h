#ifndef ASSERVISSEMENT_H
#define	ASSERVISSEMENT_H

typedef struct _PidCorrector
{
    double Kp;
    double Ki;
    double Kd;
    double erreurProportionelleMax;
    double erreurIntegraleMax;
    double erreurDeriveeMax;
    double erreurIntegrale;
    double epsilon_1;
    double erreur;
    double Consigne;

    //For Debug only
    double corrP;
    double corrI;
    double corrD;
}PidCorrector;

void SetupPidAsservissement(volatile PidCorrector* PidCorr, double Kp, double Ki, double Kd, double prop, double integ, double derive, double consigne);
double Correcteur(volatile PidCorrector* PidCorr, double erreur);
void SendPidAsservissement(volatile PidCorrector* PidCorr);
void SendPidVariablesAsservissement();

#endif	/* ASSERVISSEMENT_H */

