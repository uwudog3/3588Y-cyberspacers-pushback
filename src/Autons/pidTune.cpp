#include "main.h"

void pidTune() {
    chassis.setPose(0,0,0);

    // chassis.turnToHeading(180, 5000);
    // chassis.turnToHeading(0, 5000);
    // chassis.turnToHeading(180, 5000);
    // chassis.turnToHeading(0, 5000);
    // chassis.turnToHeading(180, 5000);
    // chassis.turnToHeading(0, 5000);
    // chassis.turnToHeading(180, 5000);
    // chassis.turnToHeading(0, 5000);

    chassis.moveToPoint(0, 24, 5000);
    chassis.turnToPoint(0, 0, 5000);
    chassis.moveToPoint(0, 0, 5000, {.forwards=true});
    chassis.turnToPoint(0, 24, 5000);
    chassis.moveToPoint(0, 24, 5000);
    chassis.turnToPoint(0, 0, 5000);
    chassis.moveToPoint(0, 0, 5000, {.forwards=true});
    chassis.turnToPoint(0, 24, 5000);
    chassis.moveToPoint(0, 24, 5000);
    chassis.turnToPoint(0, 0, 5000);
    chassis.moveToPoint(0, 0, 5000, {.forwards=true});
    chassis.turnToPoint(0, 24, 5000);
    chassis.moveToPoint(0, 24, 5000);
    chassis.turnToPoint(0, 0, 5000);
    chassis.moveToPoint(0, 0, 5000, {.forwards=true});
    chassis.turnToPoint(0, 24, 5000);
    chassis.moveToPoint(0, 24, 5000);
    chassis.turnToPoint(0, 0, 5000);
    chassis.moveToPoint(0, 0, 5000, {.forwards=true});
    chassis.turnToPoint(0, 24, 5000);
    chassis.moveToPoint(0, 24, 5000);
    chassis.turnToPoint(0, 0, 5000);
    chassis.moveToPoint(0, 0, 5000, {.forwards=true});
    chassis.turnToPoint(0, 24, 5000);
}