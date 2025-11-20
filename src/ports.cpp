#include "main.h"


// Positive direction corresponds to a long goal outtake
pros::Motor front_intake(11);
pros::Motor top_intake(8);
//top_intake should be outaking into the goals if its voltage is at 127.
pros::Motor intake_2(9);
//intake 2 should be outaking into the goals if its voltage is at 127.
pros::Motor baserightmiddle(18);
//inakeing into basket at normal
pros::Motor baseleftmiddle(-15);

pros::Optical color_sensor(4);
pros::AIVision ai_sensor(7);

pros::ADIDigitalOut hood('B');
pros::ADIDigitalOut matchload('F'); // E
// pros::ADIDigitalOut parking('');
pros::ADIDigitalOut descore('A'); // C
pros::ADIDigitalOut odom('C');
pros::ADIDigitalOut intake_up('E');

pros::Distance back_dist(5);
pros::Distance front_dist(1);
pros::Distance left_dist(3);
pros::Distance right_dist(2);
pros::Distance frontleft_dist(4);
pros::Distance backright_dist(21);
pros::Distance frontright_dist(7);
pros::Distance backleft_dist(6);