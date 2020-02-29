#include "game.h"
#include <stdlib.h>
#include <stdio.h>
void initState(StateT* state,int width,int height)
{
    state->width = width;
    state->height = height;
    state->board = malloc(width * sizeof(*(state->board)));
    for(int i = 0; i < width; i++)
    {
        state->board[i] = calloc(height, sizeof(**(state->board)));
    }
}

void freeState(StateT* state)
{
    for(int i = 0; i < state->width; i++)
    {
        free(state->board[i]);
    }    
    free(state->board);
}

void writeState(StateT* state ,FILE* out)
{
    for (int i = 0; i < state->height; i++)
    {
        for (int j = 0; j < state->width; j++)
            fprintf(out, " %d ", state->board[i][j].isLiving);
        fprintf(out,"\n");
    }

}
