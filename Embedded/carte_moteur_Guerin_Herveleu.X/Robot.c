#include "robot.h"
#include "IO.h"
#include "PWM.h" 
#include "main.h"
volatile ROBOT_STATE_BITS robotState;

void PWMSetSpeedConsigne(float vitesseEnPourcents, char moteur) {
    if (moteur == MOTEUR_D) {
        robotState.vitesseDroiteConsigne = vitesseEnPourcents;
    }
    if (moteur == MOTEUR_G) {
        robotState.vitesseGaucheConsigne = vitesseEnPourcents;
    }
}


