#include "main.h"

void auton1() {
    chassis.setPose(positionFromRaycast(back_dist.get() * MM_TO_IN, BACK_DIST_OFFSET, WEST), positionFromRaycast(right_dist.get() * MM_TO_IN, RIGHT_DIST_OFFSET, SOUTH), 90);

    front_intake.move(127);
    intake_2.move(127);

    // color_sort_on = true;

// Auton 1

chassis.moveToPoint(-23.119, -19.952, 5000, {.maxSpeed=127});
chassis.moveToPoint(-4.034, -44.453, 5000, {.maxSpeed=127});
chassis.moveToPoint(-4.034, -35.427, 5000, {.forwards=false, .maxSpeed=127});
chassis.moveToPoint(-34.983, -34.911, 5000, {.maxSpeed=127});
chassis.moveToPoint(-47.621, -46.259, 5000, {.maxSpeed=127});
chassis.moveToPoint(-66.964, -47.032, 5000, {.maxSpeed=127});
chassis.moveToPoint(-23.893, -46.517, 5000, {.maxSpeed=127});


}