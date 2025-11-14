#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void right7ball() {
    odom.set_value(false);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get() * MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH),90);

    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);

    // pick up trio
    chassis.moveToPoint(-22, -22, 250, {.maxSpeed=100, .minSpeed = 100, .earlyExitRange = 36});
    chassis.moveToPoint(-22, -22, 2000, {.maxSpeed = 100, .minSpeed = 100, .earlyExitRange = 5});

    // matchload
    chassis.turnToPoint(-45,-48,500);
    chassis.moveToPoint(-45,-48,1500,{.forwards=true,.maxSpeed=127, .earlyExitRange=1});
    chassis.waitUntil(20);
    matchload.set_value(true);
    chassis.turnToHeading(270,1000, {}, false);
    pros::delay(100);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, -48, 1000, {.forwards=true, .maxSpeed=70,.minSpeed=70});
    pros::delay(1000);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(300);
    // left_mg.move(45);
    // right_mg.move(45);
    // pros::delay(580);

    // goal

    chassis.moveToPoint(-24, -48, 1400, {.forwards=false,.maxSpeed=127,.minSpeed=80, .earlyExitRange=1},false);
    // pto.set_value(false);
    // baseleftmiddle.move(127);
    // baserightmiddle.move(127);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(2500);
    matchload.set_value(false);
    pto.set_value(true);
    front_intake.move(127);
    top_intake.move(127);
    intake_2.move(100);

    // descore
    chassis.moveToPoint(-33, -30, 1800, {.maxSpeed=80, .minSpeed=5});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToPoint(-10, -43, 1000, {.forwards=false});
    chassis.moveToPoint(-10, -43, 1500, {.forwards=false, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(-120, 500);

    odom.set_value(false);
    matchload.set_value(false);

}