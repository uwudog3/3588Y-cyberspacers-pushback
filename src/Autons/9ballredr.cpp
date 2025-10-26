#include "drive.hpp"
#include "main.h"

void pid_test() {
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
    chassis.moveToPoint(-5.9, -45.5, 1400,{.maxSpeed=90},false);
    chassis.moveToPoint(-30,-32,800,{.forwards=false,.minSpeed=115},false);
    chassis.moveToPoint(-63,-52,900,{.maxSpeed=86,.minSpeed=75},false);
    // chassis.moveToPose(-65.5, -51.5, 263, 1800,{.minSpeed=55});
    chassis.moveToPoint(-64.5,-51.5,800,{.maxSpeed=79.5});
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
    pros::delay(2500);
    Low.set_value(true);
    Swiper.set_value(true);
    matchload.set_value(false);
    pros::delay(50);
    baserightmiddle.move(0);
    baseleftmiddle.move(0);
    front_intake.move(127);
    top_intake.move(0);
    intake_2.move(0);
    chassis.moveToPoint(-45, -52, 500,{},false);
    chassis.moveToPoint(-45,-38,900,{.forwards=false},false);
    chassis.turnToHeading(260, 600);
    right_mg.move(-127);
    left_mg.move(-127);
    pros::delay(100);
    Swiper.set_value(false);
    pros::delay(420);
    right_mg.move(0);
    left_mg.move(0);
    front_intake.move(0);
}