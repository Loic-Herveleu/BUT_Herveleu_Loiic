/*

 * File:   IO.c

 */



#include <xc.h>

#include "IO.h"
#include "main.h"


void InitIO()

{

    // IMPORTANT : d�sactiver les entr�es analogiques, sinon on perd les entr�es num�riques

    ANSELA = 0; // 0 desactive

    ANSELB = 0;

    ANSELC = 0;

    ANSELD = 0;

    ANSELE = 0;

    ANSELF = 0;

    ANSELG = 0;



    //********** Configuration des sorties : _TRISxx = 0 ********************************

    // LED

    _TRISC10 = 0;  // LED Orange

    _TRISG6 = 0; //LED Blanche

    _TRISG7 = 0; // LED Bleue
    
    
    // Moteurs 

     _TRISB14 = 0;   //In1 Motor 1

    _TRISB15 = 0;   //In2 Motor 1
    
     _TRISC6 = 0;   //In1 Motor 6

    _TRISC7 = 0;   //In2 Motor 6



    //********** Configuration des entr�es : _TRISxx = 1 ********************************   
    _TRISC0 = 1;    //telem�tre 
    _TRISC11 = 1;
    _TRISG9 = 1;
    _TRISB1 = 1;
    _TRISE15 = 1;
    
    
    //***********Configuration UART******************************************************
    
    _U1RXR = 24; //Remappe la RPI24 sur l'entr�e Rx1
    _RP36R = 0b00001;   //Remappe la sortie TX1 vers RP36
}

