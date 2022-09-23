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
            ADCClearConversionFinishedFlag();;
            unsigned int *result = ADCGetResult();
            float volts = ((float) result[0]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreDroit = 34 / volts - 5;
            volts = ((float)result[2]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreCentre = 34 / volts - 5;
            volts = ((float) result[4]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreGauche = 34 / volts - 5;
            volts = ((float) result[3]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreEXTGauche = 34 / volts - 5;
            volts = ((float) result[1]) * 3.3 / 4096 * 3.2;
            robotState.distanceTelemetreEXTDroit = 34 / volts - 5;
            
        }

        if (robotState.distanceTelemetreGauche <30) {
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
    //Fonction Operating
    
    
    
    // fin main
}