#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp"

pros::MotorGroup right_mg({19, -18, 20});
pros::MotorGroup left_mg({-16, 15, -17});

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_mg, // left motor group
                              &right_mg, // right motor group
                              10, // 10 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              450, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// imu
pros::Imu imu(14);
// horizontal tracking wheel encoder
pros::Rotation horizontal_encoder(-13);
pros::Rotation vertical_encoder(12);
// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2*(96/((102.7+100.24+100.02+102.48+102.31)/5)), 1.457);
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2*(96/((99.19+100.47+101.84+99.18+99.64)/5)), 0.354);
// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10.7, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              63.5, // derivative gain (kD)
                                              0, // anti windup
                                              3, // small error range, in inches
                                              300, // small error range timeout, in milliseconds
                                              10, // large error range, in inches
                                              1000, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              28.5, // derivative gain (kD)
                                              0, // anti windup
                                              3, // small error range, in degrees
                                              300, // small error range timeout, in milliseconds
                                              10, // large error range, in degrees
                                              1000, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);