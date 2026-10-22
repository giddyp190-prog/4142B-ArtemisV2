#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

#include "liblvgl/llemu.hpp"
#include "robotConfig.h"
#include "autons.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::Task screen_task([&]() {
        while (true) {
			pros::lcd::register_btn0_cb(setAutonSelection);

            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Heading: %f", chassis.getPose().theta); // heading

			pros::lcd::print(4, "Auton: ");
			switch (autonSelection) {
				case 0:
					pros::lcd::print(5, "Red Left");
					break;
				case 1:
					pros::lcd::print(5, "Red Right");
					break;
				case 2:
					pros::lcd::print(5, "Blue Left");
					break;
				case 3:
					pros::lcd::print(5, "Blue Right");
					break;
				case 4:
					pros::lcd::print(5, "Skills");
					break;
			};
            // delay to save resources
            pros::delay(20);
        }
    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	switch (autonSelection) {
		case 0:
			redLeft();
			break;
		case 1:
			redRight();
			break;
		case 2:
			blueLeft();
			break;
		case 3:
			blueRight();
			break;
		case 4:
			skills();
			break;
	};
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	
}