#ifndef ROBOT_H
#define ROBOT_H

#include "asservissement.h"


typedef struct robotStateBITS {

    union {

        struct {
            unsigned char taskEnCours;
            float vitesseGaucheConsigne;
            float vitesseGaucheCommandeCourante;
            float vitesseDroiteConsigne;
            float vitesseDroiteCommandeCourante;
            float distanceTelemetreDroit;
            float distanceTelemetreCentre;
            float distanceTelemetreGauche;
            float distanceTelemetreExDroit;
            float distanceTelemetreExGauche;
            double vitesseDroitFromOdometry;
            double vitesseGaucheFromOdometry;
            double vitesseLineaireFromOdometry;
            double vitesseAngulaireFromOdometry;
            double xPosFromOdometry_1;
            double yPosFromOdometry_1;
            double angleRadianFromOdometry_1;
            double xPosFromOdometry;
            double yPosFromOdometry;
            double angleRadianFromOdometry;
            double CorrectionVitesseLineaire;
            double CorrectionVitesseAngulaire;
            
            PidCorrector PidX;
            PidCorrector PidTheta;
        }
        ;
    }
    ;
} ROBOT_STATE_BITS;

extern volatile ROBOT_STATE_BITS robotState;
#endif /* ROBOT_H */