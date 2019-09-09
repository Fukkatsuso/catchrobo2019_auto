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

		Instruction(660,	1,	0,	2,	Mode::NonLinearAcc), // アーム伸ばす
		Instruction(660,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(475,	1,	1,	1.5,Mode::LinearAcc), // アーム引く
		Instruction(475,	1,	1,	0.5,	Mode::Zero), // 待機

		Instruction(660,	1,	0,	2,	Mode::NonLinearAcc), // アーム伸ばす
		Instruction(660,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(440,	1,	1,	1.5,Mode::LinearAcc), // アーム引く
		Instruction(440,	1,	1,	0.5,	Mode::Zero), // 待機

		Instruction(440,	1,	0,	1,	Mode::Zero), // ワーク持ち上げ
		Instruction(340,	1,	0,	1,	Mode::LinearAcc), // ワーク落とす

		Instruction(660,	1,	0,	2,	Mode::NonLinearAcc), // アーム伸ばす
		Instruction(660,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(440,	1,	1,	1.5,Mode::LinearAcc), // アーム引く
		Instruction(440,	1,	1,	0.5,	Mode::Zero), // 待機

		Instruction(440,	1,	0,	1,	Mode::Zero), // ワーク持ち上げ
		Instruction(340,	1,	0,	1,	Mode::LinearAcc), // ワーク落とす

		Instruction(340,	0,	0,	1,	Mode::Zero)
};


#endif /* DEFAULT_INSTRUCTIONS_H_ */
