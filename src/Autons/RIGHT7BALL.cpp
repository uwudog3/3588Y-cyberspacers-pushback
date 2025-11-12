#include "drive.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include "utils.hpp"

void right7ball() {
   odom.set_value(false);
    // chassis.setPose(-46.847,-14.278,90);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get() * MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH),90);
    // chassis.setPose()


    // 7-ball low goal side (31)

    front_intake.move(127);
    intake_2.move(100);
    top_intake.move(127);
    hood.set_value(false);
    pto.set_value(true);

    // pick up trio

    chassis.moveToPoint(-22, -26, 250, {.maxSpeed=127, .minSpeed = 60, .earlyExitRange = 36});
    chassis.moveToPoint(-22, -26, 2000, {.maxSpeed = 60, .minSpeed = 60, .earlyExitRange = 8});
    pros::delay(500);
    chassis.turnToPoint(-45, -48, 500);

    // matchload

    chassis.moveToPoint(-25, -25, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1});
    matchload.set_value(true);
    chassis.moveToPoint(-62, -51, 1500, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(100);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(900);
    pros::delay(1450);
    
    //move to goal
        
    chassis.moveToPoint(-24, -48.5, 2000, {.forwards=false, .maxSpeed=127});
    pto.set_value(false);
    baseleftmiddle.move(127);
    baserightmiddle.move(127);
    front_intake.move(-20);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(3000);
    matchload.set_value(false);

    // descore
    chassis.moveToPoint(-46, -37.5, 1500, {.minSpeed=5, .earlyExitRange=1.5});
    chassis.turnToHeading(-90, 1000, {.minSpeed=5, .earlyExitRange=1.25});

    chassis.moveToPoint(-14, -36.5, 2000, {.forwards=false, .minSpeed=5, .earlyExitRange = 3});
    chassis.waitUntil(17);
    chassis.turnToHeading(-120, 2000);

    odom.set_value(false);



}