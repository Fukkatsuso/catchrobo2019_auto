/*
 * default_instructions.h
 *
 *  Created on: 2019/09/06
 *      Author: mutsuro
 */

#ifndef DEFAULT_INSTRUCTIONS_H_
#define DEFAULT_INSTRUCTIONS_H_

#include "module/instruction.h"

#define INST_NUM 20
#define INIT_R 0 // rの初期値

// r, cylinder_base, cylinder_hand, duration, acc
Instruction default_inst[INST_NUM] =
{
		Instruction(INIT_R,	0,	0,	1,	Mode::LinearAcc), // init
		Instruction(INIT_R,	0,	0,	3,	Mode::Zero), // 待機
		Instruction(INIT_R,	1,	0,	1.5,Mode::Zero), // baseを前に

		Instruction(670,	1,	0,	2,	Mode::NonLinearAcc), // アーム伸ばす
		Instruction(670,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(480,	1,	1,	1.5,Mode::LinearAcc), // アーム引く
		Instruction(480,	1,	1,	1,	Mode::Zero), // 1秒待機

		Instruction(670,	1,	0,	2,	Mode::NonLinearAcc), // アーム伸ばす
		Instruction(670,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(445,	1,	1,	1.5,Mode::LinearAcc), // アーム引く
		Instruction(445,	1,	1,	1,	Mode::Zero), // 1秒待機

		Instruction(445,	1,	0,	1,	Mode::Zero), // ワーク持ち上げ
		Instruction(300,	1,	0,	1,	Mode::LinearAcc), // ワーク落とす

		Instruction(670,	1,	0,	2,	Mode::NonLinearAcc), // アーム伸ばす
		Instruction(670,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(445,	1,	1,	1.5,Mode::LinearAcc), // アーム引く
		Instruction(445,	1,	1,	1,	Mode::Zero), // 1秒待機

		Instruction(445,	1,	0,	1,	Mode::Zero), // ワーク持ち上げ
		Instruction(300,	1,	0,	1,	Mode::LinearAcc), // ワーク落とす

		Instruction(300,	0,	0,	1,	Mode::Zero)
};


#endif /* DEFAULT_INSTRUCTIONS_H_ */
