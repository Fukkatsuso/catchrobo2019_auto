#include "mbed.h"
#include "init2.h"
#include "pin_assign.h"
#include "module/functions.h"
#include "module/joint_motor.h"
#include "module/mode.h"
#include "module/instruction.h"
#include "module/queue.h"
#include "default_instructions.h"


JointMotor<FnkOut> motor_r(&pwm_r, &enc_r);

Timer pid_timer;
Timer timer;


void led_all(int onoff)
{
	led1.write(onoff); led2.write(onoff); led3.write(onoff); led4.write(onoff);
}


#define BUFF_ARRIVE 3 // [mm]
#define WAIT_ARRIVE 10
inline bool has_arrived(int cnt_r)
{
	return (cnt_r >= WAIT_ARRIVE);
}


int main() {
	float pid_gain_r[3] = {0, 0, 0};
	float r_now; // エンコーダーで読んだ現在値
	float r_next = INIT_R;
	float r_start = INIT_R;
	float r_target = INIT_R;
	float r_dist = 0;
	int r_cnt_arrive = 0;

	float now_t; // 時刻

	Instruction inst;
	Queue<Instruction> queue_inst;
	for (int i=0; i<INST_NUM; i++) {
		queue_inst.push(default_inst[i]);
	}

	led_all(1);

	wait_ms(300); //全ての基板の電源が入るまで待つ
	pc.baud(921600);

	motor_r.pid_setting(pid_gain_r, &pid_timer);

	inst = queue_inst.front();
	r_cnt_arrive = WAIT_ARRIVE;

	cylinder_base.write(0);
	cylinder_hand.write(0);
	led_all(0);

	while(1){
		AdjustCycle(1000);

		now_t = timer.read();

		// アームのモーター
		switch (inst.acc) {
		case Mode::LinearAcc:
			r_next = r_start + linear_accel_pos(inst.duration, r_dist, now_t);
			break;
		case Mode::NonLinearAcc:
			r_next = r_start + sin_accel_pos(inst.duration, r_dist, now_t);
			break;
		}

		motor_r.move_to(r_next);
		cylinder_base.write(inst.cylinder_base);
		cylinder_hand.write(inst.cylinder_hand);

		r_now = motor_r.get_now();
		r_cnt_arrive = counter_update(r_cnt_arrive, r_now, inst.r, BUFF_ARRIVE);

		if (has_arrived(r_cnt_arrive)) {
			if (queue_inst.length() > 1) {
				queue_inst.pop();
				inst = queue_inst.front();
				r_start  = r_target;
				r_target = inst.r - R_OFFSET;
				r_dist   = r_target - r_start;
				r_cnt_arrive = 0;
				timer.reset();
				timer.start();
			}
			else {
				r_dist = 0; // 停止
			}
		}

		pc.printf("gain: %1.4f %1.4f %1.4f  ", pid_gain_r[0], pid_gain_r[1], pid_gain_r[2]);
		pc.printf("r: %4.1f  r_next: %4.1f", r_now, r_next);
//		pc.printf("cyl_base: %d  cyl_hand: %d  ", cylinder_base.read(), cylinder_hand.read());
		pc.printf("\r\n");
	}
}

