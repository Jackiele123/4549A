#include "main.h"
#include "motor_sensor_init.h"
#include "drive.h"
#include "all_used.h"
#include "lcd.h"


void initialize()  {
	// task init
	pros::task_t tracking_task = pros::c::task_create(tracking_update, (void*)NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "TRACKING TASK");
	pros::task_t velocity_task = pros::c::task_create(tracking_velocity, (void*)NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "VELOCITY TASK");
	pros::task_t auto_selecter_task = pros::c::task_create(auto_selecter, (void*)NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "AUTO SELECTER TASK");
}

void disabled() {}

void competition_initialize() {}
