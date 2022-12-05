#ifndef ROBOT_H
#define ROBOT_H

typedef struct robotStateBITS {
unsigned char taskEnCours;
float vitesseGaucheConsigne;
float vitesseGaucheCommandeCourante;
float vitesseDroiteConsigne;
float vitesseDroiteCommandeCourante;
float distanceTelemetreDroit;
float distanceTelemetreGauche;
float distanceTelemetreCentre;
float distanceTelemetreEXTDroit;
float distanceTelemetreEXTGauche;
}ROBOT_STATE_BITS;

extern volatile ROBOT_STATE_BITS robotState;

#endif /* ROBOT_H */