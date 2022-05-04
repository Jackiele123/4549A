#include "main.h"
#include "motor_setup.h"
#include "motor_sensor_init.h"
#include "drive.h"
#include "all_used.h"

void opcontrol() {
	// global variables
	int stickArray[4]; // temporary power until limited
	int power[4]; // power to the array

	while (true) {
		// printf("inertial orienation %f \n\n", inertial.get_rotation());
		// printf("odom orienation %f \n\n", radToDeg(orientation));
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			stickArray[0] = 127;
			stickArray[2] = 127;
		} else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			stickArray[0] = -127;
			stickArray[2] = -127;
		} else {
			stickArray[0] = 0;
			stickArray[2] = 0;
		}
		// stickArray[0] = powf(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X), 3) / powf(127, 2);
		stickArray[1] = powf(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), 3) / powf(127, 2);
		// stickArray[2] = powf(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), 3) / powf(127, 2);
		stickArray[3] = powf(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y), 3) / powf(127, 2);
		// loops through array and removes values under 15 from the calculation
		for (size_t j = 0; j < 4; j++) {
			if (abs(stickArray[j]) < 15) {
				stickArray[j] = 0;
			}
			// for x values remove if they are under 30
			if (j == 0 || j == 2) {
				if (127 - abs(stickArray[j]) < 30) {
					if (stickArray[j] > 0)
						stickArray[j] = 127;
					else
						stickArray[j] = -127;
				}
			}
		}
		// tank drive with mecanum calculations
		power[0] = stickArray[1] + stickArray[0];
		power[1] = stickArray[1] - stickArray[0];
		power[2] = stickArray[3] - stickArray[2];
		power[3] = stickArray[3] + stickArray[2];
		// loops through all power values to check if they are above the limit (127)
		for (size_t i = 0; i < 4; i++) {
			if (abs(power[i]) > 127) {
				if (power[i] > 0) {
					power[i] = 127;
				} else {
					power[i] = -127;
				}
			}
		}
		// enabling the drive back stack toggle
			// sets drive to power
			drive_left = power[0];
			drive_left_b = power[1];
			drive_right = power[2];
			drive_right_b = power[3];

		pros::delay(20);
	}

}
