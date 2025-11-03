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
pros::Motor intake_2(9);
//intake 2 should be outaking into the goals if its voltage is at 127.
pros::Motor baserightmiddle(18);
//inakeing into basket at normal
pros::Motor baseleftmiddle(-15);
pros::Optical color_sensor(4);

pros::ADIDigitalOut pto('A');
pros::ADIDigitalOut hood('D');
pros::ADIDigitalOut matchload('C');
pros::ADIDigitalOut parking('E');
pros::ADIDigitalOut descore('G');
pros::ADIDigitalOut odom('F');
pros::ADIDigitalOut intake_up('H');

pros::Distance back_dist(5);
pros::Distance front_dist(3);
pros::Distance left_dist(1);
pros::Distance right_dist(2);
pros::Distance frontleft_dist(6);
pros::Distance backright_dist(7);
pros::Distance frontright_dist(21);