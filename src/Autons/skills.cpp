#include "main.h"


// for going into basket
// pto.set_value(true);
// front_intake.move(127);
// intake_2.move(-127);
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



void skills() {

    chassis.setPose(positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, WEST), positionFromRaycast(front_dist.get()*MM_TO_IN, FRONT_DIST_OFFSET, SOUTH), 180);
    pto.set_value(true);
    front_intake.move(127);
    intake_2.move(127);
    top_intake.move(127);
    hood.set_value(false);
    matchload.set_value(true);

    chassis.moveToPoint(-48, -48, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(270, 1000, {},false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, SOUTH), chassis.getPose().theta);
    chassis.moveToPoint(-62, -51, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
    pros::delay(2000);
    chassis.moveToPoint(-48, -65, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(false);
    chassis.moveToPoint(36, -62, 6000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(48, -48, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), chassis.getPose().theta);

    chassis.moveToPoint(21, -48, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
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

    chassis.moveToPoint(62, -48, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
    pros::delay(2000);
    chassis.moveToPoint(21, -48, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
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

    chassis.moveToPoint(41, -24, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(41, 47, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(90, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(left_dist.get()*MM_TO_IN, LEFT_DIST_OFFSET, NORTH), chassis.getPose().theta);

    matchload.set_value(true);
    chassis.moveToPoint(62, 49, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
    pros::delay(2000);
    chassis.moveToPoint(34, 65, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    matchload.set_value(false);
    chassis.moveToPoint(-24, 63, 6000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(-48, 48, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1});
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.setPose(chassis.getPose().x, positionFromRaycast(right_dist.get()*MM_TO_IN, RIGHT_DIST_OFFSET, NORTH), chassis.getPose().theta);
    chassis.moveToPoint(-21, 48, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
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
    chassis.moveToPoint(-62, 48, 2000, {.forwards=true, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1}, false);
    pros::delay(2000);
    chassis.moveToPoint(-21, 48, 2000, {.forwards=false, .maxSpeed=100, .minSpeed=5, .earlyExitRange=1},false);
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
}