// stepper.h
//modify by jorge luis martinez suarez.
//06/05/2023
#ifndef STEPPER_H
#define STEPPER_H
#define stepsperrev 4096
void stepper_half_drive(int step);
void stepper_set_rpm(int rpm);
void stepper_step_angle(float angle, int direction, int rpm);

#endif
