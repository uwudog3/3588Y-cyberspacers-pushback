#pragma once

#define LEFT9BALL 1
#define LEFT7BALL 2
#define LEFTMIDDLEGOAL 3
#define RIGHT9BALL 4
#define RIGHT7BALL 5
#define RIGHTLOWGOAL 6
#define SKILLS 7

extern void left9ball();
extern void left7ball();
extern void leftMiddleGoal();
extern void right9ball();
extern void right7ball();
extern void rightLowGoal();
extern void skills();
extern void pidTune();

extern bool color_sort_on;
extern bool color_state;