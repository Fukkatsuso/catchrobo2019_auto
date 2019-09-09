/*
 * mode.h
 *
 *  Created on: 2019/08/26
 *      Author: mutsuro
 */

#ifndef MODE_H_
#define MODE_H_


class Mode
{
public:
	enum Accelaration
	{
		LinearAcc,
		NonLinearAcc,
		Zero
	};

	enum State
	{
		Wait,
		Run,
		StartRoutine,
		EndRoutine,
		End
	};
};


#endif /* MODE_H_ */
