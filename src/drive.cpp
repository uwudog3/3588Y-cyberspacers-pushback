#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/adi.hpp"
#include "utils.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup right_mg({19, 18, 20});
pros::MotorGroup left_mg({-16, -15, -17});

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_mg, // left motor group
                              &right_mg, // right motor group
                              11.5, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// imu
pros::Imu imu(14);
// horizontal tracking wheel encoder
pros::Rotation horizontal_encoder(-13);
pros::Rotation vertical_encoder(-12);

lemlib::TrackingWheel leftTracking(&left_mg, lemlib::Omniwheel::NEW_325, -11.5/2, 450);
lemlib::TrackingWheel rightTracking(&right_mg, lemlib::Omniwheel::NEW_325, 11.5/2, 450);

// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2 * 96/102.41, -33*MM_TO_IN); // 96/((102.7+100.24+100.02+102.48+102.31)/5
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2 * 96/102.058, -8*MM_TO_IN); // 96/((99.19+100.47+101.84+99.18+99.64)/5
// odometry settings
lemlib::OdomSensors sensors(&leftTracking, // vertical tracking wheel 1, set to null
                            &rightTracking, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(12, // proportional gain (kP)
                                              0.0, // integral gain (kI)
                                              70, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in inches
                                              300, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              100 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(5, // proportional gain (kP)
                                              0.00, // integral gain (kI)
                                              55.5, // derivative gain (kD)
                                              30, // anti windup
                                              1, // small error range, in degrees
                                              300, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);


// // lateral PID controller
// lemlib::ControllerSettings lateral_controller(10.7, // proportional gain (kP)
//                                               0.0, // integral gain (kI)
//                                               63.5, // derivative gain (kD)
//                                               0, // anti windup
//                                               1, // small error range, in inches
//                                               300, // small error range timeout, in milliseconds
//                                               3, // large error range, in inches
//                                               500, // large error range timeout, in milliseconds
//                                               0 // maximum acceleration (slew)
// );

// // angular PID controller
// lemlib::ControllerSettings angular_controller(3, // proportional gain (kP)
//                                               0.05, // integral gain (kI)
//                                               28.5, // derivative gain (kD)
//                                               30, // anti windup
//                                               1, // small error range, in degrees
//                                               300, // small error range timeout, in milliseconds
//                                               3, // large error range, in degrees
//                                               500, // large error range timeout, in milliseconds
//                                               0 // maximum acceleration (slew)
// );

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);