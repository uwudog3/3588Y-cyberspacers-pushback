#include "drive.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"

void red_left_9(){

    // Setup
    chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), 90);
    pto.set_value(true);
    pros::delay(100);
    front_intake.move(127);
    intake_2.move(-50);

    // Start Auton

    // Get trio
    chassis.moveToPoint(-15, 27, 2000, {.forwards = true, .maxSpeed = 70, .minSpeed = 50, .earlyExitRange = 3});
    chassis.turnToPoint(-5.5, 42, 300, {.maxSpeed = 70, .minSpeed = 50, .earlyExitRange = 5});
    
    // Get long goal balls
    chassis.moveToPoint(-6, 42, 1000, {.forwards = true, .maxSpeed = 80});
    
    // Back up and go to matchloader
    chassis.moveToPoint(-24, 31, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 127, .earlyExitRange = 5});
    chassis.moveToPoint(-42, 45, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 15, .earlyExitRange = 3});
    chassis.turnToHeading(270, 2000, {.minSpeed=5, .earlyExitRange=2});
    matchload.set_value(true);
    chassis.moveToPoint(-58, 48.25, 1000, {.forwards = true, .maxSpeed = 127, .minSpeed = 70});
    pros::delay(1100);
    
    // Score into long goal
    chassis.moveToPoint(-23, 48, 2000, {.forwards = false, .maxSpeed = 80, .minSpeed = 20}, false);

    pto.set_value(false);
    pros::delay(100);
    hood.set_value(true);
    baseleftmiddle.move(127);
    baserightmiddle.move(127);
    intake_2.move(127);
    top_intake.move(127);
    front_intake.move(-20);
    pros::delay(3000);

    // Descore

    pto.set_value(true);
    baseleftmiddle.move(0);
    baserightmiddle.move(0);
    intake_2.move(0);
    top_intake.move(0);
    front_intake.move(0);
    pros::delay(100);

    descore.set_value(true);
    chassis.moveToPoint(-40, 47, 2000, {.maxSpeed = 127, .minSpeed = 5, .earlyExitRange = 3});
    chassis.turnToPoint(-24, 63, 2000, {.forwards = false, .minSpeed = 5, .earlyExitRange = 3});
    chassis.moveToPoint(-24, 63, 2000, {.forwards = false, .maxSpeed = 127, .minSpeed = 5, .earlyExitRange = 3});
    chassis.turnToHeading(270, 400, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-5, 63, 2000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntil(1);
    descore.set_value(false);
}