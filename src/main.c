#include "env.h"
#include <stdio.h>

int main(void)
{
    Position agent_pos = {.row = 1, .col = 1};
    StepResult result; 
    result = env_step(agent_pos, ACTION_RIGHT);
    result = env_step(result.pos, ACTION_RIGHT);
    result = env_step(result.pos, ACTION_DOWN);
    result = env_step(result.pos, ACTION_DOWN);

    env_print(result.pos);

    return 0;
}