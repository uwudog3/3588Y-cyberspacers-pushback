#include "main.h"
#include "autons.hpp"
#include "drive.hpp"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "utils.hpp"

int selected_auton = SKILLS;
bool auton_selected = false;
bool is_sorting = false;

bool outtake = false;

bool matchload_state = false;
bool parking_state = false;
bool descore_state = false;
bool intake_up_state = false;

bool prev_matchload_state = false;
bool prev_parking_state = false;
bool prev_descore_state = false;
bool prev_intake_up_state = false;
bool prev_color_state = false;

bool color_sort_on = false;
bool color_sorting= false;
bool color_state = false;

const char* auton_names[] = {
    "None",
    "Left 9 Ball",
    "Left 7 Ball", 
    "Left Middle Goal",
    "Right 9 Ball",
    "Right 7 Ball",
	"Right Low Goal",
    "Skills", 
	"Super Low Goal",
	"Super Middle Goal",
	"PID Tune"
};

//red color hues (0-10 and 343<)

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
    auton_selected = true;
}

void on_left_button() {
    if (!auton_selected) {
        selected_auton--;
        if (selected_auton < 1) selected_auton = 10; // Wrap to last auton
    }
}

void on_right_button() {
    if (!auton_selected) {
        selected_auton++;
        if (selected_auton > 10) selected_auton = 1; // Wrap to first auton
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
	pros::lcd::register_btn0_cb(on_left_button);   // Left button
    pros::lcd::register_btn1_cb(on_center_button); // Center button  
    pros::lcd::register_btn2_cb(on_right_button);  // Right button

	chassis.calibrate();
	color_sensor.set_led_pwm(100);

	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
	chassis.setPose(0,0,0);

	pros::Task screen_task([&] {
		while (!auton_selected) {
		// pros::lcd::clear();
		pros::lcd::print(0, "Auton Selector");
		pros::lcd::print(1, "< %s >", auton_names[selected_auton]);
		pros::lcd::print(2, "Press center to select");
		pros::lcd::print(3, "Selected: %d", selected_auton);
		pros::delay(100);
	}
        
		// Display selected auton
		pros::lcd::print(0, "Auton Selected!");
		pros::lcd::print(1, "%s", auton_names[selected_auton]);
		pros::lcd::print(2, "ID: %i", selected_auton);
		pros::lcd::clear_line(3);
	});

	//color sort task


	// color sort for blue
	// pros::Task color_sort_blue([&] (){

	// 	while (true){

	// 		double current_hue = color_sensor.get_hue();

	// 		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || outtake || color_sort_on){
	// 			if(color_state){
	// 				if ((current_hue > 0 && current_hue < 10)||current_hue > 343) 
	// 				{
	// 					top_intake.move(127);
	// 					pros::delay(300);
	// 				}
	// 				else 
	// 				{
	// 					top_intake.move(-120);
	// 				}
	// 			}
	// 			else 
	// 			{
	// 				if ((current_hue > 0 && current_hue < 10)||current_hue > 343) 
	// 				{
	// 					top_intake.move(-127);
	// 					pros::delay(300);
	// 				}
	// 				else 
	// 				{
	// 					top_intake.move(120);
	// 				}
	// 			}
	// 		}
	// 		else {
	// 			top_intake.move(0);
	// 		}
	// 		pros::delay(30);

	// 	}

	// });
	
	// //color sort for red
	// pros::Task color_sort([&] (){

	// 	while (true){

	// 		double current_hue = color_sensor.get_hue();

	// 		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) || outtake || color_sort_on){
	// 			if ((current_hue > 0 && current_hue < 10)||current_hue>343) {
	// 				top_intake.move(-127);
	// 				color_sorting=true;
	// 				pros::delay(270);
	// 				color_sorting=false;
	// 			}
	// 		}
	// 		pros::delay(50);
	// 	}
	// });

	// chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST),positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), 90);
	pros::Task distance_resets([&]{
		while(true)
		{
			float frontReading = front_dist.get()*MM_TO_IN;
			float leftReading = left_dist.get()*MM_TO_IN;
			float rightReading = right_dist.get()*MM_TO_IN;
			float backReading = back_dist.get()*MM_TO_IN;
			float frontLeftReading = frontleft_dist.get() * MM_TO_IN;
			float frontRightReading = frontright_dist.get() * MM_TO_IN;
			float backRightReading = backright_dist.get() * MM_TO_IN;
			float backLeftReading = backleft_dist.get() * MM_TO_IN;

			float frontConfidence=front_dist.get_confidence();
			float leftConfidence=left_dist.get_confidence();
			float rightConfidence=right_dist.get_confidence();
			float backConfidence=back_dist.get_confidence();
			float frontLeftConfidence=frontleft_dist.get_confidence();
			float frontRightConfidence=frontright_dist.get_confidence();
			float backRightConfidence=backright_dist.get_confidence();
			float backLeftConfidence=backleft_dist.get_confidence();

			lemlib::Pose currentPose = chassis.getPose();

			float estimated_x = currentPose.x;
			float estimated_y = currentPose.y;

			float x_deviation = 144;
			float y_deviation = 144;

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
			else if (fabs(normalizedTheta - 45) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = NE;
			}
			else if (fabs(normalizedTheta - 135) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = SE;
			}
			else if (fabs(normalizedTheta - 315) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = NW;
			}
			else if (fabs(normalizedTheta - 225) < RAYCAST_RESET_ANGLE_RANGE/2.0) {
				parallel = true;
				wallDirection = SW;
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
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						estimated_x = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_y = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					case SOUTH:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, WEST);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, SOUTH);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, EAST);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, NORTH);
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						estimated_x = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_y = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					case EAST:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, SOUTH);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, EAST);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, NORTH);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, WEST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_x = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					case WEST:
						estimatedRightPos = positionFromRaycast(rightReading, RIGHT_DIST_OFFSET, NORTH);
						estimatedFrontPos = positionFromRaycast(frontReading, FRONT_DIST_OFFSET, WEST);
						estimatedLeftPos = positionFromRaycast(leftReading, LEFT_DIST_OFFSET, SOUTH);
						estimatedBackPos = positionFromRaycast(backReading, BACK_DIST_OFFSET, EAST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (leftConfidence * estimatedLeftPos + rightConfidence *estimatedRightPos)/(leftConfidence+rightConfidence);
						estimated_x = (frontConfidence * estimatedFrontPos + backConfidence * estimatedBackPos)/(frontConfidence+backConfidence);
						break;
					case NE:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, EAST);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, NORTH);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, WEST);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, SOUTH);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_x = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					case SE:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, SOUTH);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, EAST);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, NORTH);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, WEST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_x = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_y = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					case NW:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, NORTH);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, WEST);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, SOUTH);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, EAST);
						x_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						y_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_x = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_y = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					case SW:
						estimatedRightPos = positionFromRaycast(frontRightReading, FRONTRIGHT_DIST_OFFSET, WEST);
						estimatedFrontPos = positionFromRaycast(frontLeftReading, FRONTLEFT_DIST_OFFSET, SOUTH);
						estimatedLeftPos = positionFromRaycast(backLeftReading, BACKLEFT_DIST_OFFSET, EAST);
						estimatedBackPos = positionFromRaycast(backRightReading, BACKRIGHT_DIST_OFFSET, NORTH);
						y_deviation = fabs(estimatedFrontPos - estimatedBackPos);
						x_deviation = fabs(estimatedLeftPos - estimatedRightPos);
						estimated_y = (frontLeftConfidence * estimatedFrontPos + backRightConfidence * estimatedBackPos) / (frontLeftConfidence + backRightConfidence);
						estimated_x = (backLeftConfidence * estimatedLeftPos + frontRightConfidence * estimatedRightPos) / (backLeftConfidence + frontRightConfidence);
						break;
					default:
						std::printf("Invalid wall direction");
						break;
				}

				error_x = fabs(estimated_x - currentPose.x);
				error_y = fabs(estimated_y - currentPose.y);

				// if(error_x>RAYCAST_RESET_MIN_ERROR && error_x < RAYCAST_RESET_MAX_ERROR)
				// {
				// 	chassis.setPose(estimated_x,chassis.getPose().y,chassis.getPose().theta);
				// }
				// if(error_y>RAYCAST_RESET_MIN_ERROR && error_y<RAYCAST_RESET_MAX_ERROR)
				// {
				// 	chassis.setPose(chassis.getPose().x,estimated_y,chassis.getPose().theta);
				// }
				if(x_deviation>=RAYCAST_RESET_MIN_ERROR&&x_deviation<=RAYCAST_RESET_MAX_ERROR&&error_x>0.3)
				{
					chassis.setPose(estimated_x, chassis.getPose().y,chassis.getPose().theta);
					std::printf("X pos reset! %.3f Deviation: %.3f\n",estimated_x,x_deviation);
				}
				if(y_deviation>=RAYCAST_RESET_MIN_ERROR&&y_deviation<=RAYCAST_RESET_MAX_ERROR&&error_y>0.3)
				{
					chassis.setPose(chassis.getPose().x,estimated_y,chassis.getPose().theta);
					std::printf("Y pos reset! %.3f Deviation: %.3f\n", estimated_y,y_deviation);
				}
			}
			pros::delay(50);
		}
	});

	pros::Task print_coordinates([=](){
		while(true)
		{
			if(true)
			{
				controller.print(0,0,"Color:%iX:%.2fY:%.2fT:%.2f",color_state,chassis.getPose().x,chassis.getPose().y,chassis.getPose().theta);
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
void disabled() {
	left_mg.brake();
	right_mg.brake();
}

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

	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);

	switch(selected_auton)
	{
		case 1:
			left9ball();
			break;
		case 2:
			left7ball();
			break;
		case 3:
			leftMiddleGoal();
			break;
		case 4:
			right9ball();
			break;
		case 5:
			right7ball();
			break;
		case 6:
			rightLowGoal();
			break;
		case 7:
			skills();
			break;
		case 8:
			superLowGoal();
			break;
		case 9:
			superMiddleGoal();
			break;
		case 10:
			pidTune();
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
	bool loadertech=false;
	while (true) {
		bool intake_up_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
		bool matchload_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
		bool color_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);

		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	
		chassis.arcade(leftY, rightX/1.75);

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)&&color_sorting==false)
		{
			top_intake.move(127);
		}
		else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && color_sorting==false)
		{
			top_intake.move(0);
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			front_intake.move(127);
			intake_2.move(100);
			hood.set_value(false);
			intake_up.set_value(false);
		}
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			front_intake.move(-81);
			intake_2.move( 50);
		}
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			hood.set_value(true);
			pros::delay(50);
			intake_2.move(127);
			top_intake.move(127);
			intake_up.set_value(false);
		}
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			intake_2.move(65);
			top_intake.move(-30);
			intake_up.set_value(false);
		}
		else
		{
			hood.set_value(false);
			pros::delay(20);
			front_intake.move(0);
			intake_2.move(0);
			intake_up.set_value(false);
		}

		bool descore_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);

		if(matchload_pressed && !prev_matchload_state)
		{
			matchload_state = !matchload_state;
			matchload.set_value(matchload_state);
		}

		if(descore_pressed && !prev_descore_state)
		{
			descore_state = !descore_state;
			descore.set_value(descore_state);
		}

		if(intake_up_pressed && !prev_intake_up_state)
		{
			intake_up_state = !intake_up_state;
			intake_up.set_value(intake_up_state);
			pros::delay(80);
		}

		if(color_pressed && !prev_color_state)
		{
			color_state = !color_state;
		}

		prev_matchload_state = matchload_pressed;
		prev_descore_state = descore_pressed;
		prev_intake_up_state = intake_up_pressed;
		prev_color_state = color_pressed;

		//}
		pros::delay(10); // 25 ms = 0.025 seconds
	}
}