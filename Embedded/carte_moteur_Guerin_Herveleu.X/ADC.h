/* 
 * File:   ADC.h
 * Author: loich
 *
 * Created on 17 septembre 2022, 15:10
 */

#ifndef ADC_H
#define	ADC_H
void InitADC1(void);
void ADC1StartConversionSequence();
unsigned int * ADCGetResult(void);
unsigned char ADCIsConversionFinished(void);
oid ADCClearConversionFinishedFlag(void);

#endif	/* ADC_H */

