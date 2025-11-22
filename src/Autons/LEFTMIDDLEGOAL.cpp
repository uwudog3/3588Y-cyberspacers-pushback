#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void leftMiddleGoal() {
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get() * MM_TO_IN, LEFT_DIST_OFFSET, NORTH),90);

    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);

    // pick up trio
    chassis.moveToPoint(-23, 23, 250, {.maxSpeed=80, .minSpeed = 100, .earlyExitRange = 36});
    chassis.moveToPoint(-23, 23, 2000, {.maxSpeed = 80, .minSpeed = 100, .earlyExitRange = 5});

    // pick up long goal balls
    
    // chassis.moveToPoint(-7.75, 44.25, 800, {.maxSpeed=80, .minSpeed = 5});

    // score middle goal
    chassis.moveToPoint(-22, 22, 2000, {.forwards=false, .maxSpeed=110, .minSpeed=5});
    chassis.turnToPoint(-11, 11, 500, {.forwards=false});
    chassis.moveToPoint(-11, 11, 1000, {.forwards=false, .maxSpeed=60}, false);
    front_intake.move(-15);
    intake_2.move(90);
    top_intake.move(-80);
    intake_up.set_value(false);
    pros::delay(2000);
    front_intake.move(127);
    top_intake.move(127);
    intake_2.move(110);


    // matchload
    chassis.moveToPoint(-45,45.5,2000,{.forwards=true,.maxSpeed=90,.minSpeed=5,.earlyExitRange=1});
    chassis.waitUntil(20);
    matchload.set_value(true);
    chassis.turnToHeading(270,500, {}, false);
    pros::delay(100);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, 48, 800, {.forwards=true, .maxSpeed=90, .minSpeed=45,.earlyExitRange=1},true);
    pros::delay(800);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(300);
    // left_mg.move(45);
    // right_mg.move(45);
    // pros::delay(580);

    // goal
    chassis.moveToPoint(-25, 49, 2000, {.forwards=false,.maxSpeed=45,.minSpeed=45, .earlyExitRange=0.75},false);
    front_intake.move(-15);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(2100);
    matchload.set_value(false);
    front_intake.move(127);
    top_intake.move(127);
    intake_2.move(100);

    // descore
    chassis.moveToPoint(-40, 37.5, 1500, {.minSpeed=5, .earlyExitRange=1});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToHeading(90, 1000, {}, false);
    pros::delay(100);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);


    chassis.moveToPose(-10, 36, 90, 2000, {.forwards=true, .minSpeed=5, .earlyExitRange = 1});
    chassis.turnToHeading(120, 500);

    matchload.set_value(false);

}