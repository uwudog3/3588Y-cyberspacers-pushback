#include "drive.hpp"
#include "main.h"

void pid_test() {
    Low.set_value(true);
    pros::delay(20);
    chassis.setPose(0, 0, 0);
    chassis.angularPID.kP=1 ;
    chassis.turnToHeading(180, 10000);
}