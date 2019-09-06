/*
 * instruction.h
 *
 *  Created on: 2019/08/26
 *      Author: mutsuro
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "mbed.h"
#include "mode.h"


// モードと目標地点の設定
// 目標地点はフィールド基準で
struct Instruction
{
public:
	Instruction(){}

	Instruction(float r, int cylinder_base, int cylinder_hand, float duration, enum Mode::Accelaration acc):
		r(r), cylinder_base(cylinder_base), cylinder_hand(cylinder_hand), duration(duration), acc(acc) {}

	float r;
	int cylinder_base;
	int cylinder_hand;
	float duration;
	Mode::Accelaration acc;
};


#endif /* INSTRUCTION_H_ */
