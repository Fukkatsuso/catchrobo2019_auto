/*
 * default_instructions.h
 *
 *  Created on: 2019/09/06
 *      Author: mutsuro
 */

#ifndef DEFAULT_INSTRUCTIONS_H_
#define DEFAULT_INSTRUCTIONS_H_

#include "module/instruction.h"

#define INST_NUM 5
#define INIT_R 10

// r, cylinder_base, cylinder_hand, duration, acc
Instruction default_inst[INST_NUM] =
{
		Instruction(INIT_R,	 0,	 0,	 1,	 Mode::LinearAcc),
		Instruction(INIT_R,	 1,	 0,	 1,	 Mode::LinearAcc),
		Instruction(1000,	 1,	 0,	 1,	 Mode::LinearAcc),
		Instruction(1000,	 1,	 1,	 1,	 Mode::LinearAcc),
		Instruction(600,	 1,	 1,	 1,	 Mode::LinearAcc),
};


#endif /* DEFAULT_INSTRUCTIONS_H_ */
