#include "drive.hpp"
#include "main.h"

void pid_test() {
    Low.set_value(true);
    Switch.set_value(false);
    Swiper.set_value(false);
    pros::delay(50);
    chassis.setPose(-72+(back_dist.get()*MM_TO_IN)+BACK_DIST_OFFSET, -72+(right_dist.get()*MM_TO_IN)+RIGHT_DIST_OFFSET, 90);
    front_intake.move(120);
    intake_2.move(-120);
    chassis.turnToPoint(-17, -25, 400,{},false);
    top_intake.move(0);
    intake_2.move(-120);
    chassis.moveToPose(-15, -28, 120,1200, {.minSpeed=70});
    chassis.moveToPoint(-5.7, -45.5, 1400,{.maxSpeed=90});
    chassis.moveToPoint(-30,-32,1200,{.forwards=false,.minSpeed=115});
    matchload.set_value(true);
    chassis.moveToPose(-64, -52.5, 265, 2000,{.minSpeed=45},false);
    chassis.moveToPoint(-53,-52.5,1500,{.forwards=false},false);
    chassis.moveToPoint(-63,-52.5,500);
    pros::delay(920);
    chassis.moveToPose(-25,-50,265,1000,{.forwards=false,.minSpeed=115,.earlyExitRange=0.25},false);
    Low.set_value(false);
	Switch.set_value(true);
    pros::delay(50);
	baserightmiddle.move(127);
	baseleftmiddle.move(127);
	intake_2.move(-127);
	front_intake.move(-40);
	top_intake.move(127);
}