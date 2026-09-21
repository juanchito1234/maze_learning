#include "env.h"
#include <stdio.h>
#include <stdbool.h>

static const char maze[MAZE_HEIGTH][MAZE_WIDTH] = 
{
    {'#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#'},
    {'#', '.', '.', 'M', '#'},
    {'#', '#', '#', '#', '#'},
};

void env_print(Position agent_pos)
{
    for (int row = 0; row < MAZE_HEIGTH; row++)
    {
        for (int col = 0; col < MAZE_WIDTH; col++)
        {
            if (row == agent_pos.row && col == agent_pos.col)
            {
                putchar('@');
            }
            else
            {
                putchar(maze[row][col]);
            }
        }
        putchar('\n');
    }
}

bool env_is_valid(Position agent_pos)
{
    if (agent_pos.row >= MAZE_HEIGTH || agent_pos.col >= MAZE_WIDTH)
    {
        return false;
    }
    if (agent_pos.row < 0 || agent_pos.col < 0)
    {
        return false;
    }

    return maze[agent_pos.row][agent_pos.col] != '#';
}

StepResult env_step(Position pos, Action act)
{
    Position next = pos;
    switch(act)
    {
        case ACTION_UP: next.row -=1 ; break;
        case ACTION_DOWN: next.row += 1; break;
        case ACTION_LEFT: next.col -= 1; break;
        case ACTION_RIGHT: next.col += 1; break;
        default: break;
    }

    StepResult result;

    if (!env_is_valid(next))
    {
        result.pos = pos;
        result.reward = -1;
        result.done = false;

        return result;
    }

    result.pos = next;
    if (maze[pos.row][pos.col] == 'M')
    {
        result.reward = 10;
        result.done = true;
    }
    else
    {
        result.reward = -0.1f;
        result.done = false;
    }

    return result;
}
