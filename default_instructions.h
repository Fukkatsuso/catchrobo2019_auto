/*
 * default_instructions.h
 *
 *  Created on: 2019/09/06
 *      Author: mutsuro
 */

#ifndef DEFAULT_INSTRUCTIONS_H_
#define DEFAULT_INSTRUCTIONS_H_

#include "module/instruction.h"

#define INST_NUM 13
#define INIT_R 0 // rの初期値

// r, cylinder_base, cylinder_hand, duration, acc
Instruction default_inst[INST_NUM] =
{
		// 初期位置
		Instruction(INIT_R,	0,	0,	1,	Mode::LinearAcc), // init
		Instruction(INIT_R,	0,	0,	1,	Mode::Zero, Mode::Wait), // 待機
		// スタート時
		Instruction(INIT_R,	1,	0,	1,	Mode::Zero), // baseを前に

		// かき集めルーティンx2
		Instruction(660,	1,	0,	2,	Mode::NonLinearAcc, Mode::StartRoutine), // アーム伸ばす
		Instruction(660,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(440,	1,	1,	1.2,Mode::LinearAcc), // アーム引く
		Instruction(440,	1,	0,	1,	Mode::Zero), // ワーク持ち上げ
		Instruction(340,	1,	0,	0.5,Mode::LinearAcc, Mode::EndRoutine), // ワーク落とす

		Instruction(610,	1,	0,	1,	Mode::NonLinearAcc, Mode::StartRoutine), // アーム伸ばす
		Instruction(610,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(440,	1,	1,	1,	Mode::LinearAcc), // アーム引く
		Instruction(440,	1,	0,	1,	Mode::Zero), // ワーク持ち上げ
		Instruction(340,	1,	0,	0.5,Mode::LinearAcc, Mode::EndRoutine), // ワーク落とす
};


#define ROUTINE_INST_NUM 5
Instruction routine_inst[ROUTINE_INST_NUM] = {
		Instruction(610,	1,	0,	1,	Mode::NonLinearAcc, Mode::StartRoutine), // アーム伸ばす
		Instruction(610,	1,	1,	1,	Mode::Zero), // hand下す
		Instruction(440,	1,	1,	1,	Mode::LinearAcc), // アーム引く
		Instruction(440,	1,	0,	1,	Mode::Zero), // ワーク持ち上げ
		Instruction(340,	1,	0,	0.5,Mode::LinearAcc, Mode::EndRoutine), // ワーク落とす
};

#define END_INST_NUM 3
Instruction end_inst[END_INST_NUM] = {
		Instruction(340,	1,	0,	2,		Mode::NonLinearAcc),
		Instruction(0,		0,	0,	1.5,	Mode::NonLinearAcc),
		Instruction(0,		0,	0,	1,		Mode::Zero, Mode::End)
};


#endif /* DEFAULT_INSTRUCTIONS_H_ */
