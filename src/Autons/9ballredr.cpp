#include "drive.hpp"
#include "main.h"

void nineballredr() {
    pto.set_value(true);
    hood.set_value(false);
    descore.set_value(false);
    pros::delay(50);
    chassis.setPose(-72+(back_dist.get()*MM_TO_IN)+BACK_DIST_OFFSET, -72+(right_dist.get()*MM_TO_IN)+RIGHT_DIST_OFFSET, 90);
    front_intake.move(120);
    intake_2.move(120);
    top_intake.move(0);
    chassis.turnToPoint(-16, -25, 400,{},false);
    chassis.moveToPoint(-16, -28, 1200, {.minSpeed=70},false);
    chassis.moveToPose(-5.9, -45.5, 110,1400,{.maxSpeed=90},false);
    chassis.moveToPoint(-36,-28,1000,{.forwards=false,.minSpeed=115},false);
    chassis.moveToPoint(-50,-51,1000,{},false);
    matchload.set_value(true);
    chassis.moveToPoint(-50,-61,1000);
    pros::delay(1800);
    matchload.set_value(false);
    chassis.moveToPoint(-21,-50,1200,{.forwards=false,.maxSpeed=95,.earlyExitRange=0.3},false);
    pto.set_value(false);
	hood.set_value(true);
    pros::delay(50);
	baserightmiddle.move(127);
	baseleftmiddle.move(127);
	intake_2.move(-127);
	top_intake.move(127);
    pros::delay(2500);
    pto.set_value(true);
    hood.set_value(true);
    matchload.set_value(false);
    pros::delay(50);
    baserightmiddle.move(0);
    baseleftmiddle.move(0);
    front_intake.move(127);
    top_intake.move(0);
    intake_2.move(0);
    chassis.moveToPoint(-38,-40,900,{},false);
    chassis.turnToHeading(260, 600);
    right_mg.move(127);
    left_mg.move(127);
    pros::delay(100);
    hood.set_value(false);
    pros::delay(420);
    right_mg.move(0);
    left_mg.move(0);
    front_intake.move(0);
}