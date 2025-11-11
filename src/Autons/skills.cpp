#include "drive.hpp"
#include "main.h"
#include "utils.hpp"


// for going into basket
// pto.set_value(true);
// front_intake.move(127);
// intake_2.move(127);
// top_intake.move(127);
// hood.set_value(false);

// for outtaking long goal
// pto.set_value(false);
// baseleftmiddle.move(127);
// baserightmiddle.move(127);
// front_intake.move(-20);
// intake_2.move(127);
// top_intake.move(127);
// hood.set_value(true);

//for outtaking middle goal
//intake_2.move(72);
//top_intake.move(-80);



void skills() {

    chassis.setPose(positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, SOUTH), 180);
    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(110);
    top_intake.move(127);
    hood.set_value(false);
    matchload.set_value(true);

    chassis.moveToPoint(-48, -46, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(270, 1000, {},false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    #pragma region 1st matchload
    chassis.moveToPoint(-62, -51, 1500, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(100);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(900);

    chassis.moveToPoint(-48, -60, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(false);
    chassis.moveToPoint(34, -62, 6000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(40, -45, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    chassis.moveToPoint(20, -48, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=80, .earlyExitRange=1}, false);
    pto.set_value(false);
    baseleftmiddle.move(127);
    baserightmiddle.move(127);
    front_intake.move(-20);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    matchload.set_value(true);

    pros::delay(3000);
    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(false);

    #pragma region 2nd matchload
    chassis.moveToPoint(62, -48, 1500, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(100);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(900);

    
    chassis.moveToPoint(21, -48, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=80, .earlyExitRange=1}, false);
    pto.set_value(false);
    baseleftmiddle.move(127);
    baserightmiddle.move(127);
    front_intake.move(-20);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(3000);
    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(120);
    top_intake.move(127);
    hood.set_value(false);

    chassis.moveToPoint(40, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(48, 45, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    matchload.set_value(true);
    
    #pragma region 3rd matchload
    chassis.moveToPoint(62, 48, 1500, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(100);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(900);
    
    chassis.moveToPoint(34, 65, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(false);
    chassis.moveToPoint(-24, 63, 6000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(-40, 47, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-21, 48, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=80, .earlyExitRange=1}, false);
    pto.set_value(false);
    baseleftmiddle.move(127);
    baserightmiddle.move(127);
    front_intake.move(-20);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    matchload.set_value(true);
    pros::delay(3000);
    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(-127);
    top_intake.move(127);
    hood.set_value(false);

    #pragma region 4th matchload    
    chassis.moveToPoint(-62, 48, 1500, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    left_mg.move(-50);
    right_mg.move(-50);
    pros::delay(100);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(900);
    
    chassis.moveToPoint(-21, 48, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=80, .earlyExitRange=1},false);
    pto.set_value(false);
    baseleftmiddle.move(127);
    baserightmiddle.move(127);
    front_intake.move(-20);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(3000);
    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(-127);
    top_intake.move(127);
    hood.set_value(false);
    matchload.set_value(false);

    // Get middle mixed balls after 4th matchload

    chassis.moveToPoint(-40,45,2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-23,23,2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.turnToPoint(-23.5, -28, 500);
    chassis.moveToPoint(-23.5, -28, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    chassis.moveToPoint(-36,36,2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.turnToPoint(-8, 8, 1000, {.forwards=false});
    chassis.moveToPoint(-8, 8, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=50, .earlyExitRange=1}, true);
    intake_2.move(72);
	top_intake.move(-80);
}