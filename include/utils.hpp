#pragma once
#include <string>

const float MM_TO_IN=0.0393701;

const float FRONT_DIST_OFFSET = 220 * MM_TO_IN;
const float LEFT_DIST_OFFSET = 174 * MM_TO_IN;
const float RIGHT_DIST_OFFSET = 142 * MM_TO_IN;
const float BACK_DIST_OFFSET = 160 * MM_TO_IN;

const float RAYCAST_RESET_ANGLE_RANGE = 2.0;
const float RAYCAST_RESET_MIN_ERROR = 0.3;
const float RAYCAST_RESET_MAX_ERROR = 3.0;

enum WALL
{
    NORTH,SOUTH,EAST,WEST,
};

extern float positionFromRaycast(float sensorReading, float sensorOffset, WALL wall);

extern float normalizeAngle(float angle);