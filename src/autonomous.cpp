#include "main.h"
#include "drive.h"
#include "motor_setup.h"
#include "motor_sensor_init.h"
#include "all_used.h"
#include "lcd.h"

void Turn_Reset(float amount, float resetAmount, float speed, float timeout) {
	position_turn(amount, timeout, speed);
	position_turn(resetAmount, timeout, speed);
}

void autonomous() {
  printf("PositionX: %f || PositionY: %f || Orientation: %f \n \n", position.x, position.y, orientation);
  printf("position.x %f \n", position.x);
  printf("position.y %f \n", position.y);
  reset_position_full(0, 0, 0);
  beginning_orientation = 0;
  int initial_time = pros::millis();
  inertial.reset();


  pros::delay(3000);

  //Inches driving
  position_turn(90, 2000, 127);
  driveInches(0, 0, 20, 100, 0.05, 20000);
  driveInches(20, 0, -20, -100, 0.05, 20000);
  driveInches(0, 0, 20, 100, 0.05, 20000);
  driveInches(20, 0, -20, -100, 0.05, 20000);

  //Back and Forth
  //position_turn(90, 2000, 127);
  //position_drive2(0, 0, 25, 0, 127, 0.01, 20000);
  ////////Turn_Reset(90, 0, 127, 2000);
  //position_drive2(25, 0, 0, 0, -90, 0.05, 20000);
  ////////Turn_Reset(90, 0, 127, 2000);
  //position_drive2(0, 0, 0, 25, 127, 0.01, 20000);
  ////////Turn_Reset(45, 0, 127, 2000);
  //position_drive2(0, 25, 0, 0, -90, 0.05, 20000);

  //Swerve Check
  /*position_drive2(0, 0, -7, 25, 0, 90, 0.1, 20000);
  text_breaker();
  position_drive2(-7, 25, -7, 0, 0, -90, 0.1, 20000);
  text_breaker();
  position_drive2(-7, 0, 0, 25, 0, 90, 0.1, 20000);
  text_breaker();
  position_drive2(0, 25, 0, 0, 0, -90, 0.1, 20000);*/

  // drive_pid_encoder(20, 20000, 90);
  printf("PositionX: %f || PositionY: %f || Orientation: %f \n \n", position.x, position.y, radToDeg(orientation));
}
