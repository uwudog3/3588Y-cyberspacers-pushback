#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void right9ball() {
    odom.set_value(false);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get() * MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH),90);

    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);

    // pick up trio
    chassis.moveToPoint(-24, -23, 250, {.maxSpeed=100, .minSpeed = 100, .earlyExitRange = 36});
    chassis.moveToPoint(-24, -23, 2000, {.maxSpeed = 100, .minSpeed = 100, .earlyExitRange = 5});

    // pick up long goal balls
    
    chassis.moveToPoint(-9, -44, 800, {.maxSpeed=100, .minSpeed = 5});

    // matchload
    chassis.moveToPoint(-24, -36, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=100, .earlyExitRange=5});
    chassis.moveToPoint(-45,-48,3000,{.forwards=false,.maxSpeed=127});
    chassis.waitUntil(20);
    matchload.set_value(true);
    chassis.turnToHeading(270,1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, -47.5, 1000, {.forwards=true, .maxSpeed=70,.minSpeed=70});
    pros::delay(1000);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(300);
    // left_mg.move(45);
    // right_mg.move(45);
    // pros::delay(580);

    // goal

    chassis.turnToPoint(-24, -48.5, 500, {.forwards=false, .minSpeed=127, .earlyExitRange=2});
    chassis.moveToPoint(-24, -48.5, 2000, {.forwards=false,.maxSpeed=127,.minSpeed=45, .earlyExitRange=1},false);
    // pto.set_value(false);
    // baseleftmiddle.move(127);
    // baserightmiddle.move(127);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(2500);
    matchload.set_value(false);
    front_intake.move(127);
    top_intake.move(127);
    intake_2.move(100);

    // descore
    chassis.moveToPoint(-36, -37, 1800, {.maxSpeed=80});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToPoint(-12, -38, 1000, {.forwards=false});
    chassis.moveToPoint(-12, -38, 1500, {.forwards=false, .minSpeed=5, .earlyExitRange=3});
    chassis.turnToHeading(-120, 500);

    odom.set_value(false);
    matchload.set_value(false);

}