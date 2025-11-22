#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void rightLowGoal() {
    odom.set_value(true);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get() * MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH),90);

    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);

    // pick up trio
    chassis.moveToPoint(-24, -23, 250, {.maxSpeed=127, .minSpeed=65, .earlyExitRange = 36});
    chassis.moveToPoint(-24, -23, 2000, {.maxSpeed=65, .minSpeed=65, .earlyExitRange = 5});

    // // pick up long goal balls
    
    // chassis.turnToPoint(-8, -44, 500, {.minSpeed=5, .earlyExitRange=3});
    // chassis.moveToPoint(-8, -44, 1200, {.maxSpeed=60, .minSpeed = 5});

    // score low goal
    // chassis.moveToPoint(-24, -24, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToPoint(-9, -9, 500, {.forwards=true}, false);
    front_intake.move(0);
    intake_up.set_value(true);
    chassis.moveToPoint(-9, -9, 1500, {.forwards=true, .maxSpeed=60, .minSpeed=45, .earlyExitRange=5}, false);
    intake_2.move(0);
    matchload.set_value(true);
    pros::delay(200);
    front_intake.move(-64);
    intake_2.move(50);
    pros::delay(700);
    intake_2.move(50);
    intake_up.set_value(false);
    matchload.set_value(false);

    // matchload

    front_intake.move(127);
    chassis.turnToPoint(-40, -45, 1000, {.forwards=false});
    chassis.moveToPose(-40,-45,270, 3000,{.forwards=false,.maxSpeed=127, .minSpeed=50});
    chassis.waitUntil(20);
    matchload.set_value(true);
    chassis.turnToHeading(270,750, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, -47.5, 800, {.forwards=true, .maxSpeed=70,.minSpeed=45});
    pros::delay(800);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(300);
    // left_mg.move(45);
    // right_mg.move(45);
    // pros::delay(580);

    // goal

    chassis.turnToPoint(-24, -48.5, 500, {.forwards=false, .minSpeed=40, .earlyExitRange=2});
    chassis.moveToPoint(-24, -48.5, 1000, {.forwards=false,.maxSpeed=80,.minSpeed=40, .earlyExitRange=1},false);
    // pto.set_value(false);
    // baseleftmiddle.move(127);
    // baserightmiddle.move(127);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(1500);
    matchload.set_value(false);
    front_intake.move(127);
    top_intake.move(127);
    intake_2.move(100);

    // descore
    chassis.moveToPoint(-48, -37, 1800, {.maxSpeed=80});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPose(-16, -38, 270, 1500, {.forwards=false, .minSpeed=80, .earlyExitRange=3});
    chassis.turnToHeading(-120, 500);

    odom.set_value(true);
    matchload.set_value(false);
}