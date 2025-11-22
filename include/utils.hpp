#pragma once
#include <string>

const float MM_TO_IN = 0.0393701;

const float FRONT_DIST_OFFSET = 149 * MM_TO_IN;
const float LEFT_DIST_OFFSET = 150 * MM_TO_IN;
const float RIGHT_DIST_OFFSET = 150 * MM_TO_IN;
const float BACK_DIST_OFFSET = 123 * MM_TO_IN;
const float BACKRIGHT_DIST_OFFSET = 7.123;
const float FRONTRIGHT_DIST_OFFSET = 5.455;
const float FRONTLEFT_DIST_OFFSET = 5.461;
const float BACKLEFT_DIST_OFFSET = 7.084;

const float RAYCAST_RESET_ANGLE_RANGE = 20.0;
const float RAYCAST_RESET_MIN_ERROR = 0.0;
const float RAYCAST_RESET_MAX_ERROR = 3.0;

enum WALL
{
    NORTH,SOUTH,EAST,WEST,NE,SE,NW,SW,
};

extern float positionFromRaycast(float sensorReading, float sensorOffset, WALL wall);

extern float normalizeAngle(float angle);