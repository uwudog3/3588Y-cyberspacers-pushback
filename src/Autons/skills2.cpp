#include "autons.hpp"
#include "drive.hpp"
#include "main.h"
#include "utils.hpp"


// for going into basket
// pto.set_value(true);
// front_intake.move(127);
// intake_2.move(-127);
// top_intake.move(127);
// hood.set_value(false);

// for outtaking long goal
// pto.set_value(false);
// baseleftmiddle.move(127);
// baserightmiddle.move(127);
// front_intake.move(-20);
// intake_2.move(127);
// top_intake.move(127);
// hood.set_value(true);



void skills2() {

    color_sort_on = false;
    color_state = true;

    chassis.setPose(positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, NORTH), 0);
    
    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(100);
    hood.set_value(false);
    // odom.set_value(true);

    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(400);

    // left_mg.move(127);
    // right_mg.move(127);
    // pros::delay(1700);

    // left_mg.move(0);
    // right_mg.move(0);

    // chassis.turnToHeading(90, 1000, {}, false);
    // odom.set_value(false);
    // pros::delay(200);
    // chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    chassis.moveToPoint(-48, 45, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(true);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    color_sort_on = true;
    chassis.moveToPoint(-62, 48, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
    pros::delay(2000);
    chassis.moveToPoint(-45, 36, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(false);
    chassis.turnToPoint(-20, 21, 1000);
    chassis.moveToPoint(-20, 21, 2000, {.forwards=true, .maxSpeed=50, .minSpeed=5, .earlyExitRange=3});
    chassis.turnToPoint(-40, -8, 1000);
    chassis.moveToPoint(-40, -8, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(-40, -42, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToPoint(-18, -18, 1000);
    chassis.moveToPoint(-10, -10, 2500, {.forwards=true, .maxSpeed=50, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(-10, -10, 1000, {.forwards=true, .maxSpeed=50, .minSpeed=5, .earlyExitRange=1}, false);
    matchload.set_value(true);
    pros::delay(200);
    intake_up.set_value(true);
    front_intake.move(-100);
    intake_2.move(30);
    pros::delay(3000);
    intake_up.set_value(false);
    matchload.set_value(false);
    front_intake.move(127);
    intake_2.move(100);




}