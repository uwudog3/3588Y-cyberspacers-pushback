#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/misc.hpp"
#include "pros/optical.hpp"

extern pros::Controller controller;

extern lemlib::Chassis chassis;
extern pros::Controller controller;
extern pros::Motor front_intake;
extern pros::Motor intake_2;
extern pros::Motor top_intake;
extern pros::ADIDigitalOut pto;
extern pros::Motor baseleftmiddle;
extern pros::Motor baserightmiddle;
extern pros::Optical color_sensor;
extern pros::ADIDigitalOut hood;
extern pros::ADIDigitalOut matchload;
extern pros::ADIDigitalOut descore;
extern pros::ADIDigitalOut trap;
extern pros::ADIDigitalOut parking;

extern pros::Distance front_dist;
extern pros::Distance back_dist;
extern pros::Distance left_dist;
extern pros::Distance right_dist;
extern pros::ADIDigitalOut Swiper;
extern pros::MotorGroup right_mg;
extern pros::MotorGroup left_mg;
extern pros::ADIDigitalOut double_park;