#include "main.h"

void pidTune() {
    chassis.setPose(0,0,0);

    // chassis.turnToHeading(180, 7000);
    // chassis.turnToHeading(0, 7000);
    // chassis.turnToHeading(180, 7000);
    // chassis.turnToHeading(0, 7000);
    // chassis.turnToHeading(180, 7000);
    // chassis.turnToHeading(0, 7000);
    // chassis.turnToHeading(180, 7000);
    // chassis.turnToHeading(0, 7000);

    chassis.moveToPoint(0, 24, 7000);
    chassis.moveToPoint(0, 0, 7000, {.forwards=false});
    chassis.moveToPoint(0, 24, 7000);
    chassis.moveToPoint(0, 0, 7000, {.forwards=false});
    chassis.moveToPoint(0, 24, 7000);
    chassis.moveToPoint(0, 0, 7000, {.forwards=false});
    chassis.moveToPoint(0, 24, 7000);
    chassis.moveToPoint(0, 0, 7000, {.forwards=false});
    chassis.moveToPoint(0, 24, 7000);
    chassis.moveToPoint(0, 0, 7000, {.forwards=false});
    chassis.moveToPoint(0, 24, 7000);
    chassis.moveToPoint(0, 0, 7000, {.forwards=false});
}