#include "drive.hpp"
#include "main.h"

void right9ball() {
    odom.set_value(false);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get() * MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH),90);

    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);

    // pick up trio
    chassis.moveToPoint(-18, -28, 250, {.maxSpeed=127, .minSpeed = 60, .earlyExitRange = 36});
    chassis.moveToPoint(-18, -28, 2000, {.maxSpeed = 127, .minSpeed = 60, .earlyExitRange = 8});

    // pick up long goal balls
    
    chassis.moveToPoint(-7.6, -45, 1200, {.maxSpeed=127, .minSpeed = 5, .earlyExitRange = 3}, false);

    // matchload
    chassis.moveToPoint(-25, -24, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(125, 1000, {.maxSpeed=127, .minSpeed=127, .earlyExitRange=2.5});
    chassis.moveToPoint(-45,-51.25,2000,{.forwards=true,.maxSpeed=90,.minSpeed=5,.earlyExitRange=0.5},false);
    chassis.waitUntil(20);
    matchload.set_value(true);
    chassis.turnToHeading(270,500,{.earlyExitRange=0.25});
    chassis.moveToPoint(-63, -51.25, 800, {.forwards=true, .maxSpeed=90, .minSpeed=45,.earlyExitRange=1},false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(300);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(650);

    // goal

    chassis.moveToPoint(-24, -52, 2000, {.forwards=false,.maxSpeed=127, .earlyExitRange=0.25},false);
    pto.set_value(false);
    baseleftmiddle.move(127);
    baserightmiddle.move(127);
    front_intake.move(-20);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(2100);
    matchload.set_value(false);
    pto.set_value(true);
    front_intake.move(127);
    top_intake.move(127);
    intake_2.move(100);

    // descore
    chassis.moveToPoint(-46, -41, 1500, {.minSpeed=5, .earlyExitRange=1.75});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToHeading(-90, 1000, {.minSpeed=5, .earlyExitRange=1});

    chassis.moveToPoint(-14, -39.25, 2000, {.forwards=false, .minSpeed=5, .earlyExitRange = 3});
    chassis.waitUntil(16);
    chassis.turnToHeading(-120, 2000);


    odom.set_value(false);
    matchload.set_value(false);

}