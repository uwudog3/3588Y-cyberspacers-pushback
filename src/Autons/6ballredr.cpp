#include "main.h"
#include "drive.hpp"

void sixballredr() {
    Low.set_value(true);
    Switch.set_value(false);
    Swiper.set_value(false);
    pros::delay(50);
    chassis.setPose(-72+(back_dist.get()*MM_TO_IN)+BACK_DIST_OFFSET, -72+(right_dist.get()*MM_TO_IN)+RIGHT_DIST_OFFSET, 90);
    front_intake.move(120);
    intake_2.move(120);
    top_intake.move(0);
    chassis.turnToPoint(-17, -25, 400,{},false);
    chassis.moveToPose(-15, -28, 120,1200, {.minSpeed=70},false);
    chassis.turnToPoint(0, 0, 500,{},false);
    chassis.moveToPoint(-10, -10, 500,{.maxSpeed=100},false);
    front_intake.move(-81);
    intake_2.move(-50);
    pros::delay(1000);
    chassis.moveToPoint(-5.9, -45.5, 1400,{.maxSpeed=90},false);
    chassis.moveToPoint(-30,-32,800,{.forwards=false,.minSpeed=115},false);
    chassis.moveToPoint(-63,-52,900,{.maxSpeed=86,.minSpeed=75},false);
    chassis.moveToPoint(-64.5,-51.5,800,{.maxSpeed=80});
    matchload.set_value(true);
    pros::delay(1500);
    chassis.moveToPoint(-23.75,-52,1200,{.forwards=false,.maxSpeed=95,.earlyExitRange=0.3},false);
    Low.set_value(false);
	Switch.set_value(true);
    pros::delay(50);
	baserightmiddle.move(127);
	baseleftmiddle.move(127);
	intake_2.move(-127);
	front_intake.move(-30);
	top_intake.move(127);
}