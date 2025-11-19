#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void left7ball() {
    odom.set_value(false);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get() * MM_TO_IN, LEFT_DIST_OFFSET, NORTH),90);

    front_intake.move(127);
    intake_2.move(-105);
    top_intake.move(127);
    hood.set_value(false);

    // pick up trio
    chassis.moveToPoint(-23, 23, 250, {.maxSpeed=80, .minSpeed = 100, .earlyExitRange = 36});
    chassis.moveToPoint(-23, 23, 2000, {.maxSpeed = 80, .minSpeed = 100, .earlyExitRange = 5});

    // matchload
    chassis.turnToHeading(305, 800,{.minSpeed=127,.earlyExitRange=1});
    chassis.moveToPoint(-44,50.25,3000,{.maxSpeed=127});
    chassis.waitUntil(19);
    matchload.set_value(true);
    front_intake.move(-127);
    pros::delay(175);
    front_intake.move(127);
    chassis.turnToHeading(270,1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, 47.5, 1000, {.forwards=true, .maxSpeed=70,.minSpeed=70});
    pros::delay(850);
    // left_mg.move(-50);
    // right_mg.move(-50);
    // pros::delay(300);
    // left_mg.move(45);
    // right_mg.move(45);
    // pros::delay(580);

    // goal

    chassis.turnToPoint(-25, 48.5, 500, {.forwards=false, .minSpeed=127, .earlyExitRange=2});
    chassis.moveToPoint(-25, 49, 2000, {.forwards=false,.maxSpeed=127,.minSpeed=45, .earlyExitRange=0.75},false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    // pto.set_value(false);
    // baseleftmiddle.move(127);
    // baserightmiddle.move(127);
    pros::delay(300);
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
    chassis.moveToPoint(-46, -37.25, 1500, {.minSpeed=5, .earlyExitRange=1});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToHeading(90, 1000, {}, false);
    pros::delay(100);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    odom.set_value(false);
    matchload.set_value(false);

}