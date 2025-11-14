#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void left7ball() {
    odom.set_value(false);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get() * MM_TO_IN, LEFT_DIST_OFFSET, NORTH),90);

    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);

    // pick up trio
    chassis.moveToPoint(-22, 22, 250, {.maxSpeed=60, .minSpeed = 60, .earlyExitRange = 36});
    chassis.moveToPoint(-22, 22, 2000, {.maxSpeed = 60, .minSpeed = 60, .earlyExitRange = 5});
    
    // matchload
    chassis.moveToPoint(-24, 24, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5});
    chassis.turnToPoint(-45,45.5,1000);
    chassis.moveToPoint(-45,45.5,2000,{.forwards=true,.maxSpeed=90,.minSpeed=5,.earlyExitRange=1});
    chassis.waitUntil(20);
    matchload.set_value(true);
    chassis.turnToHeading(270,500, {}, false);
    pros::delay(100);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, 48, 800, {.forwards=true, .maxSpeed=90, .minSpeed=45,.earlyExitRange=1},false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(300);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(580);

    // goal

    chassis.moveToPoint(-24, 48, 2000, {.forwards=false,.maxSpeed=127,.minSpeed=80,.earlyExitRange=1},false);
    front_intake.move(-13);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(2100);
    matchload.set_value(false);
    front_intake.move(127);
    top_intake.move(127);
    intake_2.move(100);

    // descore
    chassis.moveToPoint(-46, 37, 1500, {.minSpeed=5, .earlyExitRange=1});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToHeading(90, 1000, {}, false);
    pros::delay(100);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);


    chassis.moveToPoint(-14, 38, 2000, {.forwards=true, .minSpeed=5, .earlyExitRange = 1});
    chassis.turnToHeading(120, 500);

    odom.set_value(false);
    matchload.set_value(false);

}