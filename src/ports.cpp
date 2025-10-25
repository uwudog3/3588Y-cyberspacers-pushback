#include "drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/optical.hpp"
#include "pros/vision.hpp"

pros::Motor front_intake(11);
//front_intake should be intaking into the basket if its voltage is at 127.
pros::Motor top_intake(8);
//top_intake should be outaking into the goals if its voltage is at 127.
pros::Motor intake_2(-9);
//intake 2 should be outaking into the goals if its voltage is at 127.
pros::Motor baserightmiddle(18);
//inakeing into basket at normal
pros::Motor baseleftmiddle(-15);
pros::Optical color_sensor(4);

pros::ADIDigitalOut Low('A');
pros::ADIDigitalOut Switch('D');
pros::ADIDigitalOut matchload('C');
pros::ADIDigitalOut double_park('E');
pros::ADIDigitalOut Swiper('G');
//A is still pto
//C is matchload tech
//D is switcher for goals and intake
//E is final double park tech
//F is weird

pros::Distance back_dist(5);
pros::Distance front_dist(3);
pros::Distance left_dist(1);
pros::Distance right_dist(2);