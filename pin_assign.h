/*
 * pin_assign.h
 *
 *  Created on: 2019/08/28
 *      Author: mutsuro
 */

#ifndef PIN_ASSIGN_H_
#define PIN_ASSIGN_H_

#include "mbed.h"
#include "module/encoder.h"
#include "module/FnkOut.h"


Serial pc(USBTX, USBRX);

FnkOut pwm_r(p25, p26);

DigitalOut cylinder_base(p21);
DigitalOut cylinder_hand(p22);


#define R_MM_PER_PULSE ((32.0 * M_PI) / 800.0)
#define R_OFFSET 0
Encoder enc_r(p9, p10, R_MM_PER_PULSE, R_OFFSET);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


#endif /* PIN_ASSIGN_H_ */
