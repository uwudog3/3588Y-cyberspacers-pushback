#include "drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/optical.hpp"

pros::Motor front_intake(-11);
//front_intake should be outaking into the goals if its voltage is at -127.
pros::Motor top_intake(8);
//top_intake should be outaking into the goals if its voltage is at 127.
pros::Motor intake_2(-9);
//intake 2 should be outaking into the goals if its voltage is at -127.
pros::Motor baserightmiddle(15);
pros::Motor baseleftmiddle(-18);
pros::Optical Color_sensor(4);

pros::ADIDigitalOut Low('A');
pros::ADIDigitalOut Switch('D');