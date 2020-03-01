#include "printFile.h"
#include <stdio.h>

void writeStateToPBM(StateT* state, FILE* out)
{
    printf("P1\n%d %d\n", state->width, state->height);
    for (int i = 1; i < state->height+1; i++)
    {
        for (int j = 1; j < state->width+1; j++)
            fprintf(out, "%d ", state->board[i][j]);
        fprintf(out,"\n");
    }

}