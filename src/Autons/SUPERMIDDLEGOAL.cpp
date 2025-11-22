#include "drive.hpp"
#include "main.h"
#include "utils.hpp"

void superMiddleGoal(){

    odom.set_value(true);
    matchload.set_value(false);
    chassis.setPose(positionFromRaycast(left_dist.get() * MM_TO_IN, LEFT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get() * MM_TO_IN, FRONT_DIST_OFFSET, NORTH),0);

    front_intake.move(127);
    intake_2.move(105);
    top_intake.move(127);
    hood.set_value(false);
    
    // matchload
    chassis.moveToPoint(-48, 46, 1000, {.forwards=true, .maxSpeed=127, .minSpeed=5}, true);
    matchload.set_value(true);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-60, 47, 700, {.forwards=true, .maxSpeed=45, .minSpeed=45}, true);
    pros::delay(700);

    // long goal score
    descore.set_value(false);
    chassis.turnToPoint(-33, 48, 500, {.forwards=false});
    
    chassis.moveToPoint(-33, 48, 1500, {.forwards=false, .maxSpeed=60, .minSpeed=5, .earlyExitRange=1}, false);
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

    // middle goal score
    chassis.moveToPoint(-43, 48, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.turnToPoint(-26, -26, 1000, {.forwards=true, .minSpeed=50, .earlyExitRange=3});
    // chassis.moveToPoint(-26, -26, 1800, {.forwards=true, .maxSpeed=60, .minSpeed=50, .earlyExitRange=5}, true);
    // pros::delay(1800);
    chassis.turnToPoint(-23, 23, 1000, {.forwards=true});
    chassis.moveToPoint(-23, 23, 2500, {.forwards=true, .maxSpeed=60, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToPoint(-12, 12, 1500, {.forwards=false});
    // chassis.turnToHeading(315, 1000);
    chassis.moveToPoint(-12, 12, 500, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToPoint(0, -1, 500, {.forwards=false}, false);
    intake_2.move(0);
    // matchload.set_value(true);
    // intake_up.set_value(true);
    pros::delay(200);
    front_intake.move(0);
    intake_2.move(72); // 72
    top_intake.move(-72);
    pros::delay(3000);
    // intake_up.set_value(false);
    // matchload.set_value(false);

    // // descore
    // chassis.moveToPoint(-36, 33, 1800, {.forwards=true, .maxSpeed=80});
    // chassis.waitUntil(3);
    // hood.set_value(false);
    // chassis.turnToHeading(90, 1000, {}, false);
    // chassis.setPose(positionFromRaycast(back_dist.get()*MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    // chassis.moveToPose(-14, 37, 90, 1500, {.forwards=true, .minSpeed=80, .earlyExitRange=3});
    // chassis.turnToHeading(120, 500);

    odom.set_value(true);
    matchload.set_value(false);
}