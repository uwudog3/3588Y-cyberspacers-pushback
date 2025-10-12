#include <atomic>
#include "main.h"
#include "drive.hpp"
// #include "lemlib/api.hpp"
// #include "pros/colors.h"
#include "pros/misc.h"
#include "pros/optical.hpp"

int AUTON_NUM = 1;

// Task function to print RGB values from color sensor
void print_rgb_task(void* param) {
	pros::Optical color_sensor(4);
	color_sensor.set_led_pwm(100);
	while (true) {
		auto rgb = color_sensor.get_rgb();
		std::string msg = "R: " + std::to_string(rgb.red) + " G: " + std::to_string(rgb.green) + " B: " + std::to_string(rgb.blue);
		pros::lcd::set_text(2, msg);
		pros::delay(500);
	}
}



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	// Start the RGB printing task only once
	pros::Task rgb_task(print_rgb_task, nullptr, "Print RGB Task");
    pros::lcd::initialize();
    pros::lcd::set_text(1, "Hello Sean!");
    pros::lcd::register_btn1_cb(on_center_button);

	chassis.calibrate();
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
void competition_initialize() {

}

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
	switch(AUTON_NUM)
	{
		case 1:
			pid_test();
			break;

	}
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
	bool pto=false;
	bool outake=true;
	//when pto = true, the robot is not in pto mode and the drive motors are enabled.
	pros::Controller controller(pros::E_CONTROLLER_MASTER);
	Low.set_value(true);
    // loop forever
	while (true) {
		// if (!is_sorting) {
			if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
				front_intake.move(127);
				intake_2.move(127);
				top_intake.move(127);
			}
			else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
			{
				front_intake.move(-81);
				intake_2.move(10);
			}
			else {
				front_intake.move(0);
				intake_2.move(0);
				top_intake.move(0);
			}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
			{
				pto=true;
				Low.set_value(false);
				pros::delay(20); // 25 ms = 0.025 seconds
				intake_2.move(90);
				front_intake.move(-20);
				top_intake.move(-90);
			}
			else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			{
				pto=true;
				Low.set_value(false);
				pros::delay(20); // 25 ms = 0.025 seconds
				Switch.set_value(true);
				pros::delay(20); // 25 ms = 0.025 seconds
				outake=false;
				intake_2.move(127);
				front_intake.move(-20);
				top_intake.move(127);
			}
			else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X))
			{
				pto=false;
				Low.set_value(true);
				pros::delay(20); // 25 ms = 0.025 seconds
				front_intake.move(0);
				baseleftmiddle.move(0);
				intake_2.move(0);
				baserightmiddle.move(0);
				top_intake.move(0);
				Switch.set_value(false);
				pros::delay(20); // 25 ms = 0.025 seconds
				outake=true;
			}
			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)&&outake==true)
			{
				outake=false;
				Switch.set_value(false);
				pros::delay(150); // 25 ms = 0.025 seconds
			}
			else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)&&outake==false)
			{
				outake=true;
				Switch.set_value(true);
				pros::delay(150); // 25 ms = 0.025 seconds
			}
			if(pto==false)
			{
				int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
				int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

				chassis.arcade(leftY, -rightX);
			}
			else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)&&pto==true){
				baseleftmiddle.move(-127);
				baserightmiddle.move(-127);
			}
			else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)&&pto==true)
			{
				baseleftmiddle.move(-90);
				baserightmiddle.move(90);
			}
		// }
		// delay to save resources
		pros::delay(25); // 25 ms = 0.025 seconds
	}
}