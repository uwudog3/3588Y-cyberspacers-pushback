#include "drive.hpp"
#include "main.h"

void pid_test() {
    Low.set_value(true);
    Switch.set_value(false);
    pros::delay(50);
    chassis.setPose(-72+(back_dist.get()*MM_TO_IN)+BACK_DIST_OFFSET, -72+(right_dist.get()*MM_TO_IN)+RIGHT_DIST_OFFSET, 90);
    front_intake.move(120);
    intake_2.move(-120);
    chassis.turnToPoint(-17, -25, 500);
    chassis.moveToPose(-17, -28, 120,1200, {.minSpeed=70});
    chassis.moveToPoint(-5.5, -45, 1400,{.maxSpeed=90});
    chassis.moveToPoint(-30,-32,1400,{.forwards=false});
    chassis.moveToPose(-52, -50, 2, 1800, {.minSpeed=90,.earlyExitRange=2}, false);
    matchload.set_value(true);
    chassis.moveToPoint(-56.5,-50,1500);
    chassis.moveToPoint(-54,-50,500,{.forwards=false});
    chassis.moveToPoint(-56.5,-50,500);
    pros::delay(1000);
    chassis.moveToPoint(-28.76,-48.6,1000,{.forwards=false});
    Low.set_value(false);
	Switch.set_value(true);
    pros::delay(50);
	baserightmiddle.move(127);
	baseleftmiddle.move(127);
	intake_2.move(127);
	front_intake.move(-40);
	top_intake.move(127);
}