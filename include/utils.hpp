#pragma once
#include <string>

const float MM_TO_IN = 0.0393701;

const float FRONT_DIST_OFFSET = 145 * MM_TO_IN;
const float LEFT_DIST_OFFSET = 175 * MM_TO_IN;
const float RIGHT_DIST_OFFSET = 156 * MM_TO_IN;
const float BACK_DIST_OFFSET = 164 * MM_TO_IN;
const float BACKRIGHT_DIST_OFFSET = 164.3 * MM_TO_IN;
const float FRONTRIGHT_DIST_OFFSET = 222 * MM_TO_IN;
const float FRONTLEFT_DIST_OFFSET = 164.3 * MM_TO_IN;
const float BACKLEFT_DIST_OFFSET = 0;

const float RAYCAST_RESET_ANGLE_RANGE = 2.0;
const float RAYCAST_RESET_MIN_ERROR = 0.3;
const float RAYCAST_RESET_MAX_ERROR = 3.0;

enum WALL
{
    NORTH,SOUTH,EAST,WEST,NE,SE,NW,SW,
};

extern float positionFromRaycast(float sensorReading, float sensorOffset, WALL wall);

extern float normalizeAngle(float angle);