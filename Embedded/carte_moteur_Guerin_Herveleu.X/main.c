#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "Robot.h"
#include "ADC.h"
#include "main.h"

unsigned int ADCValue0;
unsigned int ADCValue1;
unsigned int ADCValue2;
unsigned char stateRobot;

unsigned char nextStateRobot = 0;

int main(void) {
    /***************************************************************************************************/
    //Initialisation de l?oscillateur
    /****************************************************************************************************/
    InitOscillator();

    /****************************************************************************************************/
    // Configuration des entrées sorties
    /****************************************************************************************************/
    InitIO();

    //LED_BLANCHE = 1;
    //LED_BLEUE = 1;
    //LED_ORANGE = 1;

    // initialisation des timer
    InitTimer23();
    InitTimer1();
    InitTimer4();
    /****************************************************************************************************/
    // Boucle Principale
    InitPWM();
    InitADC1();
    /****************************************************************************************************/
    while (1) {

        //LED_BLANCHE = !LED_BLANCHE;
        //LED_BLEUE = !LED_BLEUE;
        //LED_ORANGE = !LED_ORANGE;
        //-----------------------------------------------
        //if (ADCIsConversionFinished()) {
        //ADCClearConversionFinishedFlag();
        //unsigned int * result = ADCGetResult();
        //ADCValue0=result[0];
        //ADCValue1=result[1];
        //ADCValue2=result[2];
        //}
        //-----------------------------------------------

        if (ADCIsConversionFinished()) {
            ADCClearConversionFinishedFlag();
            ;
            unsigned int *result = ADCGetResult();
            float volts = ((float) result[4]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreDroit = 34 / volts - 5;
            volts = ((float) result[2]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreCentre = 34 / volts - 5;
            volts = ((float) result[1]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreGauche = 34 / volts - 5;
            volts = ((float) result[3]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreEXTGauche = 34 / volts - 5;
            volts = ((float) result[0]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreEXTDroit = 34 / volts - 5;

        }

        if (robotState.distanceTelemetreGauche < 30) {
            LED_ORANGE = 1;
        } else {
            LED_ORANGE = 0;
        }
        //----------------------------------------
        if (robotState.distanceTelemetreCentre < 30) {
            LED_BLEUE = 1;
        } else {
            LED_BLEUE = 0;
        }
        //----------------------------------------
        if (robotState.distanceTelemetreDroit < 30) {
            LED_BLANCHE = 1;
        } else {
            LED_BLANCHE = 0;
        }
    }
    // fin main
}
//Fonction Operating

void OperatingSystemLoop(void) {
    switch (stateRobot) {
        case STATE_ATTENTE:
            timestamp = 0;
            PWMSetSpeedConsigne(0, MOTEUR_D);
            PWMSetSpeedConsigne(0, MOTEUR_G);
            stateRobot = STATE_ATTENTE_EN_COURS;

        case STATE_ATTENTE_EN_COURS:
            if (timestamp > 1000)
                stateRobot = STATE_AVANCE;
            break;

        case STATE_AVANCE:
            PWMSetSpeedConsigne(25, MOTEUR_D);
            PWMSetSpeedConsigne(25, MOTEUR_G);
            stateRobot = STATE_AVANCE_EN_COURS;
            break;

        case STATE_AVANCE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;

        case STATE_TOURNE_GAUCHE:

            PWMSetSpeedConsigne(25, MOTEUR_D);
            PWMSetSpeedConsigne(0, MOTEUR_G);
            stateRobot = STATE_TOURNE_GAUCHE_EN_COURS;
            break;

        case STATE_TOURNE_GAUCHE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;

        case STATE_TOURNE_DROITE:

            PWMSetSpeedConsigne(0, MOTEUR_D);
            PWMSetSpeedConsigne(25, MOTEUR_G);
            stateRobot = STATE_TOURNE_DROITE_EN_COURS;
            break;

        case STATE_TOURNE_DROITE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;

        case STATE_TOURNE_SUR_PLACE_GAUCHE:
            PWMSetSpeedConsigne(-20, MOTEUR_D);
            PWMSetSpeedConsigne(20, MOTEUR_G);
            stateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS;
            break;

        case STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;

        case STATE_TOURNE_SUR_PLACE_DROITE:
            PWMSetSpeedConsigne(20, MOTEUR_D);
            PWMSetSpeedConsigne(-20, MOTEUR_G);
            stateRobot = STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS;
            break;

        case STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;

        case STATE_RECULE:
            PWMSetSpeedConsigne(-10, MOTEUR_D);
            PWMSetSpeedConsigne(-10, MOTEUR_G);
            stateRobot = STATE_RECULE_EN_COURS;
            break;

        case STATE_RECULE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;

        default:
            stateRobot = STATE_ATTENTE;
            break;
    }
}

void SetNextRobotStateInAutomaticMode() {
    unsigned char positionObstacle = PAS_D_OBSTACLE;

    //Détermination de la position des obstacles en fonction des télémètres
    if (robotState.distanceTelemetreDroit < 45 && robotState.distanceTelemetreCentre > 30 && robotState.distanceTelemetreGauche > 45) //Obstacle à droite
        positionObstacle = OBSTACLE_A_GAUCHE;

    else if (robotState.distanceTelemetreDroit > 45 && robotState.distanceTelemetreCentre > 30 && robotState.distanceTelemetreGauche < 45) //Obstacle à gauche
        positionObstacle = OBSTACLE_A_DROITE;

    else if (robotState.distanceTelemetreDroit < 45 && robotState.distanceTelemetreGauche > 45) //Obstacle à droite
        positionObstacle = OBSTACLE_A_GAUCHE;

    else if (robotState.distanceTelemetreDroit > 45 && robotState.distanceTelemetreGauche < 45) //Obstacle à gauche
        positionObstacle = OBSTACLE_A_DROITE;

    else if (robotState.distanceTelemetreEXTDroit < 30 && robotState.distanceTelemetreEXTGauche > 35) //Obstacle à droite
        positionObstacle = OBSTACLE_A_DROITE;

    else if (robotState.distanceTelemetreEXTGauche < 30 && robotState.distanceTelemetreEXTDroit > 35) //Obstacle à gauche
        positionObstacle = OBSTACLE_A_GAUCHE;

    else if (robotState.distanceTelemetreCentre < 10 && !STATE_AVANCE_EN_COURS) //Obstacle en face
        positionObstacle = OBSTACLE_EN_FACE;

    else if (robotState.distanceTelemetreCentre < 18 && STATE_AVANCE_EN_COURS) //Obstacle en face
        positionObstacle = OBSTACLE_EN_FACE;

    else if (robotState.distanceTelemetreDroit > 40 && robotState.distanceTelemetreCentre > 35 && robotState.distanceTelemetreGauche > 40) //pas d?obstacle
        positionObstacle = PAS_D_OBSTACLE;

    else if (robotState.distanceTelemetreEXTDroit < 22 && robotState.distanceTelemetreEXTGauche < 22)
        positionObstacle = OBSTACLE_PARTOUT;

    else if (robotState.distanceTelemetreDroit < 22 && robotState.distanceTelemetreGauche < 22)
        positionObstacle = OBSTACLE_PARTOUT;


    //Détermination de l?état à venir du robot
    if (positionObstacle == PAS_D_OBSTACLE)
        nextStateRobot = STATE_AVANCE;

    else if (positionObstacle == OBSTACLE_A_DROITE)
        nextStateRobot = STATE_TOURNE_GAUCHE;

    else if (positionObstacle == OBSTACLE_A_GAUCHE)
        nextStateRobot = STATE_TOURNE_DROITE;

    else if (positionObstacle == OBSTACLE_EN_FACE && (robotState.distanceTelemetreDroit < robotState.distanceTelemetreGauche))
        nextStateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE;

    else if (positionObstacle == OBSTACLE_EN_FACE && (robotState.distanceTelemetreDroit > robotState.distanceTelemetreGauche))
        nextStateRobot = STATE_TOURNE_SUR_PLACE_DROITE;

    else if (positionObstacle == OBSTACLE_PARTOUT && (robotState.distanceTelemetreDroit > robotState.distanceTelemetreGauche))
        nextStateRobot = STATE_TOURNE_SUR_PLACE_DROITE;

    else if (positionObstacle == OBSTACLE_PARTOUT && (robotState.distanceTelemetreDroit < robotState.distanceTelemetreGauche))
        nextStateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE;

    //Si l?on n?est pas dans la transition de l?étape en cours
    if (nextStateRobot != stateRobot - 1)
        stateRobot = nextStateRobot;
}
