#ifndef ENV_H
#define ENV_H

#define MAZE_WIDTH 5
#define MAZE_HEIGTH 5

#include <stdbool.h>

typedef struct {
    int row;
    int col;
} Position;

typedef enum {
    ACTION_UP,
    ACTION_DOWN,
    ACTION_LEFT,
    ACTION_RIGHT,
    ACTION_COUNT
} Action;

typedef struct {
    Position pos;
    float reward;
    bool done;
} StepResult;

void env_print(Position pos);
bool env_is_valid(Position pos);
StepResult env_step(Position pos, Action act);

#endif // ENV_H