/*
 * functions.cpp
 *
 *  Created on: 2019/06/24
 *      Author: mutsuro
 */

#include "functions.h"


int limit(int value, int max, int min)
{
	if (value > max) return max;
	else if (value < min) return min;
	return value;
}


float limit(float value, float max, float min)
{
	if (value > max) return max;
	else if (value < min) return min;
	return value;
}


inline float sqrt3(float a, float b, float c)
{
	return sqrt(a*a + b*b + c*c);
}


inline float sqrt2(float a, float b)
{
	return sqrt(a*a + b*b);
}


float sin_accel_vel(float period, float dist, float now_t)
{
	if (now_t > period) return 0;

	float cosine = cos(2.0 * M_PI * now_t / period);
	return dist * (1.0 - cosine) / period;
}


float linear_accel_vel(float period, float dist, float now_t)
{
	if (now_t > period) return 0;

	return dist / period;
}


float sin_accel_pos(float period, float dist, float now_t)
{
	if (now_t > period) return dist;

	float sine = sin(2.0 * M_PI * now_t / period);
	return (dist / period) * (now_t - (period / (2.0 * M_PI)) * sine);
}


float linear_accel_pos(float period, float dist, float now_t)
{
	if (now_t > period) return dist;

	return dist * now_t / period;
}


int counter_update(int counter, float now, float target, float buff)
{
	bool ok = (fabs(target - now) < buff);
	counter += (ok ? 1 : -1);
	return (counter >= 0 ? counter : 0);
}
