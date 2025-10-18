#include "drive.hpp"
#include "main.h"

void pid_test() {
    Low.set_value(true);
    Switch.set_value(false);
    pros::delay(50);
    chassis.setPose(-72+(back_dist.get()*MM_TO_IN)+BACK_DIST_OFFSET, -72+(right_dist.get()*MM_TO_IN)+RIGHT_DIST_OFFSET, 90);
    front_intake.move(120);
    intake_2.move(120);
    top_intake.move(120);
    chassis.turnToPoint(-17, -25, 500,{},false);
    top_intake.move(0);
    intake_2.move(-120);
    chassis.moveToPose(-17, -28, 120,1200, {.minSpeed=70});
    chassis.moveToPoint(-5.75, -45, 1400,{.maxSpeed=90});
    chassis.moveToPoint(-30,-32,1200,{.forwards=false});
    chassis.moveToPose(-63, -51, 270, 2000,{.minSpeed=45});
    matchload.set_value(true);
    chassis.moveToPoint(-53,-51,1500,{.forwards=false});
    chassis.moveToPoint(-63,-51,500);
    pros::delay(920);
    chassis.moveToPose(-25,-50,270,1000,{.forwards=false,.minSpeed=95,.earlyExitRange=1.5},false);
    Low.set_value(false);
	Switch.set_value(true);
    pros::delay(50);
	baserightmiddle.move(127);
	baseleftmiddle.move(127);
	intake_2.move(127);
	front_intake.move(-40);
	top_intake.move(127);
}