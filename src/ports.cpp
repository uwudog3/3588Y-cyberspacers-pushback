#include "main.h"


// Positive direction corresponds to a long goal outtake
pros::Motor front_intake(11);
pros::Motor top_intake(8);
pros::Motor intake_2(9);
pros::Motor baserightmiddle(18);
//inakeing into basket at normal
pros::Motor baseleftmiddle(-15);

pros::Optical color_sensor(4);
pros::AIVision ai_sensor(7);

pros::ADIDigitalOut pto('A');
pros::ADIDigitalOut hood('D');
pros::ADIDigitalOut matchload('C');
pros::ADIDigitalOut descore('G');
pros::ADIDigitalOut trap('F');
pros::ADIDigitalOut parking('E');

pros::Distance back_dist(5);
pros::Distance front_dist(3);
pros::Distance left_dist(1);
pros::Distance right_dist(2);