
#ifndef PWM_H
#define	PWM_H

#define MOTEUR_G 33
#define MOTEUR_D 44

void InitPWM(void);
void PWMUpdateSpeed(void);
void PWMSetSpeedConsigne(float vitesseEnPourcents, char moteur);
//void PWMSetSpeed(float vitesseEnPourcents,float moteur);

#endif	/* PWM_H */

