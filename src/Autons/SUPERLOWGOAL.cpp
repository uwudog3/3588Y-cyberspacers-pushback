#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void superLowGoal(){

    odom.set_value(true);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(right_dist.get() * MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get() * MM_TO_IN, FRONT_DIST_OFFSET, SOUTH),180);

    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);
    
    // matchload
    chassis.moveToPoint(-48, -47, 1000, {.forwards=true, .maxSpeed=127}, true);
    matchload.set_value(true);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, -48, 900, {.forwards=true, .maxSpeed=45, .minSpeed=45, .earlyExitRange=1}, true);
    pros::delay(900);
    
    // long goal score
    descore.set_value(false);
    chassis.turnToPoint(-32, -48, 200, {.forwards=false});
    
    chassis.moveToPoint(-32, -48, 1200, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    hood.set_value(true);
    pros::delay(50);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    intake_up.set_value(false);
    pros::delay(2200);
    front_intake.move(127);
    intake_2.move(-105);
    top_intake.move(127);
    hood.set_value(false);
    matchload.set_value(false);

    // low goal score
    chassis.moveToPoint(-43, -48, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.turnToPoint(-26, -26, 1000, {.forwards=true, .minSpeed=50, .earlyExitRange=3});
    // chassis.moveToPoint(-26, -26, 1800, {.forwards=true, .maxSpeed=60, .minSpeed=50, .earlyExitRange=5}, true);
    // pros::delay(1800);
    chassis.turnToPoint(-10, -10, 1000);
    chassis.moveToPoint(-10, -10, 2200, {.forwards=true, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToPoint(0, 0, 500, {}, false);
    intake_2.move(0);
    matchload.set_value(true);
    intake_up.set_value(true);
    pros::delay(200);
    front_intake.move(-64);
    intake_2.move(50);
    pros::delay(1500);
    intake_up.set_value(false);
    matchload.set_value(false);

    // descore
    chassis.moveToPoint(-48, -37, 1800, {.forwards=false, .maxSpeed=80});
    chassis.waitUntil(3);
    hood.set_value(false);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPose(-14, -38, 270, 1500, {.forwards=false, .maxSpeed=80, .earlyExitRange=3});
    chassis.turnToHeading(-120, 500);

    odom.set_value(true);
    matchload.set_value(false);
}