#include "main.h"
#include "drive.hpp"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "utils.hpp"

int AUTON_NUM = 1;
bool is_sorting = false;

bool outtake = false;
bool matchload_state = false;
bool prev_matchload_state = false;
bool color_sort_on = false;

//red color hues (0-10 and 343<)

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
    pros::lcd::initialize();
    pros::lcd::set_text(1, "Hello Sean!");
    pros::lcd::register_btn1_cb(on_center_button);
	chassis.calibrate();
	color_sensor.set_led_pwm(100);

	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);

	//color sort task


	//color sort for blue
	// pros::Task color_sort_blue([&] (){

	// 	while (true){

	// 		double current_hue = color_sensor.get_hue();

	// 		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || outtake || color_sort_on){
	// 			if ((current_hue > 0 && current_hue < 10)||current_hue > 343) {
	// 				top_intake.move(127);
	// 				pros::delay(300);
	// 			}
	// 			else {
	// 				top_intake.move(-120);
	// 			}
	// 		}
	// 	}

	// });
	
	//color sort for red
	pros::Task color_sort([&] (){

		while (true){

			double current_hue = color_sensor.get_hue();

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || outtake || color_sort_on){
				if ((current_hue > 0 && current_hue < 10)||current_hue>343) {
					top_intake.move(-127);
					pros::delay(270);
				}
				else {
					top_intake.move(105);
				}
			}
			pros::delay(50);
		}
	});

	// chassis.setPose(0,0,0);
	chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST),positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), 90);
	pros::Task distance_resets([&]{
		while(true)
		{
			float frontReading = front_dist.get()*MM_TO_IN;
			float leftReading = left_dist.get()*MM_TO_IN;
			float rightReading = right_dist.get()*MM_TO_IN;
			float backReading = back_dist.get()*MM_TO_IN;

			float frontConfidence=front_dist.get_confidence();
			float leftConfidence=left_dist.get_confidence();
			float rightConfidence=right_dist.get_confidence();
			float backConfidence=back_dist.get_confidence();

			lemlib::Pose currentPose = chassis.getPose();

			float estimated_x = currentPose.x;
			float estimated_y = currentPose.y;

			float normalizedTheta = normalizeAngle(currentPose.theta);

			float estimatedRightPos = 0;
			float estimatedFrontPos = 0;
			float estimatedLeftPos = 0;
			float estimatedBackPos = 0;

			WALL wallDirection = NORTH;
			bool parallel = false;

			float error_x = 144.0;
			float error_y = 144.0;

			if(fabs(normalizedTheta)<RAYCAST_RESET_ANGLE_RANGE/2.0)
			{
				parallel = true;
				wallDirection = NORTH;
			}
			else if(fabs(normalizedTheta - 180)<RAYCAST_RESET_ANGLE_RANGE/2.0)
			{
				parallel = true;
				wallDirection = SOUTH;
			}
			else if(fabs(normalizedTheta - 90)<RAYCAST_RESET_ANGLE_RANGE/2.0)
			{
				parallel = true;
				wallDirection = EAST;
			}
			else if(fabs(normalizedTheta - 270)<RAYCAST_RESET_ANGLE_RANGE/2.0)
			{
				parallel = true;
				wallDirection = WEST;
			}
			else
			{
				parallel = false;
			}

			if(parallel)
			{
				switch(wallDirection)
				{
					case NORTH:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, EAST);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, NORTH);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, WEST);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, SOUTH);
						estimated_x = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_y = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					case SOUTH:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, WEST);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, SOUTH);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, EAST);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, NORTH);
						estimated_x = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_y = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					case EAST:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, SOUTH);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, EAST);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, NORTH);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, WEST);
						estimated_y = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_x = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					case WEST:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, NORTH);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, WEST);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, SOUTH);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, EAST);
						estimated_y = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_x = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					default:
						std::printf("Invalid wall direction");
						break;
				}

				error_x = fabs(estimated_x - currentPose.x);
				error_y = fabs(estimated_y - currentPose.y);

				if(error_x>RAYCAST_RESET_MIN_ERROR && error_x < RAYCAST_RESET_MAX_ERROR)
				{
					chassis.setPose(estimated_x,chassis.getPose().y,chassis.getPose().theta);
				}
				if(error_y>RAYCAST_RESET_MIN_ERROR && error_y<RAYCAST_RESET_MAX_ERROR)
				{
					chassis.setPose(chassis.getPose().x,estimated_y,chassis.getPose().theta);
				}
			}
			pros::delay(500);
		}
	});

	pros::Task print_coordinates([=](){
		while(true)
		{
			if(true)
			{
				std::cout<<std::endl;
				controller.print(0,0,"X:%.2fY:%.2fT:%.2f",chassis.getPose().x,chassis.getPose().y,chassis.getPose().theta);
				pros::delay(100);
			}
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
	// bool outake=true;
	bool loadertech=false;
	Low.set_value(true);
	while (true) {
		// if (!is_sorting) {
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			front_intake.move(127);
			intake_2.move(101);
		}
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			front_intake.move(-81);
			intake_2.move( 50);
		}
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			pto=true;
			Low.set_value(false);
			Switch.set_value(true);
			pros::delay(50);
			baserightmiddle.move(127);
			baseleftmiddle.move(127);
			intake_2.move(127);
			front_intake.move(-40);
			top_intake.move(127);
			// outtake=true;
		}
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			pto=true;
			Low.set_value(false);
			pros::delay(50);
			baseleftmiddle.move(-127);
			baserightmiddle.move(110);
			intake_2.move(110);
			front_intake.move(-40);
			top_intake.move(-127);
		}
		//  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X))
		else
		{
			pto=false;
			Low.set_value(true);
			Switch.set_value(false);
			pros::delay(20);
			front_intake.move(0);
			baseleftmiddle.move(0);
			intake_2.move(0);
			baserightmiddle.move(0);
			// outtake=false;
		}
		
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)&&loadertech==false)
		{
			loadertech=true;
			matchload.set_value(true);
			pros::delay(25);
		}
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)&&loadertech==true)
		{
			loadertech=false;
			matchload.set_value(false);
			pros::delay(25);
		}

		bool matchload_pressed = controller.get_digital(DIGITAL_A);

		if(matchload_pressed && !prev_matchload_state)
		{
			matchload_state = !matchload_state;
			matchload.set_value(matchload_state);
		}

		prev_matchload_state = matchload_pressed;

		// if(outtake)
		// {
		// 	front_intake.move(-10);
		// }
		if(pto==false)
		{
			int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
			int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		
			chassis.arcade(leftY, rightX);
		}
		//}
		pros::delay(25
		); // 25 ms = 0.025 seconds
	}
}