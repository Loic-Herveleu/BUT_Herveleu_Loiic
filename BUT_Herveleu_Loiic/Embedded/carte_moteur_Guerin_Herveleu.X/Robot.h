#ifndef ROBOT_H
#define ROBOT_H

void PWMUpdateSpeed();
void PWMSetSpeedConsigne(float vitesseEnPourcents, char moteur);

typedef struct robotStateBITS {
union {

struct {
unsigned char taskEnCours;
float vitesseGaucheConsigne;
float vitesseGaucheCommandeCourante;
float vitesseDroiteConsigne;
float vitesseDroiteCommandeCourante;
float distanceTelemetreDroit;
float distanceTelemetreGauche;
float distanceTelemetreCentre;
float distanceTelemetreEXTDroit;
float distanceTelemetreEXTGauche;}
;}
;} ROBOT_STATE_BITS;

extern volatile ROBOT_STATE_BITS robotState;
#endif /* ROBOT_H */