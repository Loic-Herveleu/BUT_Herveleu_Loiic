#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"

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

    LED_BLANCHE = 1;
    LED_BLEUE = 1;
    LED_ORANGE = 1;

    // initialisation des timer
    InitTimer23();

    InitTimer1();
    /****************************************************************************************************/
    // Boucle Principale
    InitPWM();
    InitADC1();
    /****************************************************************************************************/
    while (1) {
        //LED_BLANCHE = !LED_BLANCHE;
        //LED_BLEUE = !LED_BLEUE;
        // LED_ORANGE = !LED_ORANGE;

        if (ADCIsConversionFinished()) {
        ADCClearConversionFinishedFlag();
        unsigned int * result = ADCGetResult();
        ADCValue0=result[0];
        ADCValue1=result[1];
        ADCValue2=result[2];           
        }
    } // fin main
}