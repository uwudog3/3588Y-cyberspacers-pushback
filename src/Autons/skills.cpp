#include "drive.hpp"
#include "main.h"
#include "utils.hpp"


// for going into basket

// front_intake.move(127);
// intake_2.move(127);
// top_intake.move(127);
// hood.set_value(false);

// for outtaking long goal

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
    front_intake.move(127);
    intake_2.move(110);
    top_intake.move(127);
    hood.set_value(false);
    matchload.set_value(true);

    chassis.moveToPoint(-48, -44.5, 2000, {.forwards=true, .maxSpeed=90, .minSpeed=5, .earlyExitRange=17.25});
    chassis.turnToHeading(270, 1000, {},false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    
    #pragma region 1st matchload
    chassis.moveToPoint(-61, -48.25, 2000, {.forwards=true, .maxSpeed=60, .minSpeed=15, .earlyExitRange=1});
    pros::delay(2000);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(300);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(1000);

    chassis.moveToPoint(-37, -60, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(false);
    chassis.moveToPoint(23, -62, 6000, {.forwards=false, .maxSpeed=110, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(29, -45, 2000, {.forwards=false, .maxSpeed=110, .minSpeed=5, .earlyExitRange=5});
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    chassis.moveToPoint(21, -48, 2000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=2}, false);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    matchload.set_value(true);

    pros::delay(3000);
    front_intake.move(127);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(false);

    #pragma region 2nd matchload
    chassis.moveToPoint(61, -49.25, 2000, {.forwards=true, .maxSpeed=60, .minSpeed=15, .earlyExitRange=1});
    pros::delay(2000);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(300);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(1000);

    
    chassis.moveToPoint(21, -49, 2000, {.forwards=false, .maxSpeed=80, .minSpeed=5, .earlyExitRange=1.5}, false);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(3000);
    front_intake.move(127);
    intake_2.move(120);
    top_intake.move(127);
    matchload.set_value(false);

    chassis.moveToPoint(36, -24, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    chassis.waitUntil(5);
    hood.set_value(false);
    chassis.moveToPoint(48, 45, 2000, {.forwards=true, .maxSpeed=110, .minSpeed=5, .earlyExitRange=22});
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    matchload.set_value(true);
    
    #pragma region 3rd matchload
    chassis.moveToPoint(61, 48, 2000, {.forwards=true, .maxSpeed=60, .minSpeed=15, .earlyExitRange=0.8});
    pros::delay(2000);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(300);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(1000);
    
    chassis.moveToPoint(34, 65, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(false);
    chassis.moveToPoint(-22, 66, 6000, {.forwards=false, .maxSpeed=110, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(-36, 50, 2000, {.forwards=false, .maxSpeed=110, .minSpeed=5, .earlyExitRange=6});
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-21, 47.5, 2000, {.forwards=false, .maxSpeed=80, .minSpeed=10, .earlyExitRange=1}, false);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    matchload.set_value(true);
    pros::delay(3000);
    front_intake.move(127);
    intake_2.move(-127);
    top_intake.move(127);
    hood.set_value(false);

    #pragma region 4th matchload    
    chassis.moveToPoint(-61, 48, 2000, {.forwards=true, .maxSpeed=60, .minSpeed=15, .earlyExitRange=1});
    pros::delay(2000);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(300);
    left_mg.move(-40);
    right_mg.move(-40);
    pros::delay(200);
    left_mg.move(45);
    right_mg.move(45);
    pros::delay(1000);
    
    chassis.moveToPoint(-21, 47.5, 2000, {.forwards=false, .maxSpeed=80, .minSpeed=10, .earlyExitRange=3},false);
    matchload.set_value(false);
    front_intake.move(0);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(true);
    pros::delay(3000);
    front_intake.move(127);
    intake_2.move(-127);
    top_intake.move(127);
    hood.set_value(false);

    // park

    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN,RIGHT_DIST_OFFSET,NORTH),chassis.getPose().theta);
    // chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), 270);

    front_intake.move(127);
    top_intake.move(120);
    intake_2.move(110);
    chassis.moveToPoint(-38, 48, 2000, {.forwards=true, .maxSpeed=127}, true);
    chassis.turnToPoint(-20, 20, 1000);
    chassis.moveToPoint(-20, 20, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5}, true);
    // chassis.moveToPoint(-38, -7, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.moveToPoint(-18, -30, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.turnToPoint(-24, -24, 1000);
    // chassis.moveToPoint(-24, -24, 2000, {.forwards=true, .maxSpeed=100}, true);
    // chassis.turnToPoint(-24, 24, 1000, {.forwards=false});
    // chassis.moveToPoint(-24, 24, 2000, {.forwards=false, .maxSpeed=100}, true);
    
    chassis.turnToPoint(-11, 10, 2000, {.forwards=false});
    chassis.moveToPoint(-11, 10, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, false);
    front_intake.move(0);
    intake_2.move(90);
    chassis.turnToPoint(0, -1, 500, {.forwards=false}, false);
    pros::delay(200);
    front_intake.move(0);
    top_intake.move(-50);
    pros::delay(1400);
    top_intake.move(0);
    intake_2.move(0);
    front_intake.move(127);
    matchload.set_value(false);

    chassis.moveToPoint(-36, 30, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=100, .earlyExitRange=5}, true);
    // chassis.turnToPoint(-62, 13, 1000);
    chassis.moveToPoint(-60, 15, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    
    chassis.turnToHeading(190, 500, {}, false);
    intake_2.move(127);
    matchload.set_value(true);
    pros::delay(500);
    left_mg.move(80);
    right_mg.move(80);
    pros::delay(400);
    matchload.set_value(false);
    pros::delay(867);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    left_mg.move(-20);
    right_mg.move(-20);
    pros::delay(500);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.turnToHeading(90, 1000, {}, false);
    pros::delay(500);

    // Get middle mixed balls after 4th matchload

    // chassis.moveToPoint(-40,45,2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.moveToPoint(-23,23,2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.turnToPoint(-23.5, -28, 500);
    // chassis.moveToPoint(-23.5, -28, 2000, {.forwards=true, .maxSpeed=127, .minSpeed=5, .earlyExitRange=5}, true);
    // chassis.moveToPoint(-36,36,2000, {.forwards=false, .maxSpeed=127, .minSpeed=5, .earlyExitRange=1}, true);
    // chassis.turnToHeading(270, 1000, {}, false);
    // chassis.setPose(positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, WEST), positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    // chassis.turnToPoint(-8, 8, 1000, {.forwards=false});
    // chassis.moveToPoint(-8, 8, 2000, {.forwards=false, .maxSpeed=127, .minSpeed=50, .earlyExitRange=1}, true);
    // intake_2.move(72);
	// top_intake.move(-80);
}