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

pros::ADIDigitalOut pto('A');
pros::ADIDigitalOut hood('H');
pros::ADIDigitalOut matchload('E'); // E
// pros::ADIDigitalOut parking('');
pros::ADIDigitalOut descore('C'); // C
pros::ADIDigitalOut odom('G');
pros::ADIDigitalOut intake_up('F');

pros::Distance back_dist(5);
pros::Distance front_dist(1);
pros::Distance left_dist(3);
pros::Distance right_dist(2);
pros::Distance frontleft_dist(6);
pros::Distance backright_dist(7);
pros::Distance frontright_dist(21);
pros::Distance backleft_dist(4);