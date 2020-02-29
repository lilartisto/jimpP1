#include "map.h"
#include <stdlib.h>
#include <stdio.h>
void initState(StateT* state,int width,int height)
{
    state->width = width;
    state->height = height;
    width+=2;//paski na boku
    height+=2;
    state->board = malloc(width * sizeof(*(state->board)));
    for(int i = 0; i < width; i++)
    {
        state->board[i] = calloc(height, sizeof(**(state->board)));
    }
}

void freeState(StateT* state)
{
    for(int i = 0; i < state->width+2; i++)
    {
        free(state->board[i]);
    }    
    free(state->board);
}

void writeState(StateT* state ,FILE* out)
{
    //przerzucic do printpbm.h
    //printf P1 szeroksc wysokosc
    for (int i = 1; i < state->height+1; i++)
    {
        for (int j = 1; j < state->width+1; j++)
            fprintf(out, " %d ", state->board[i][j]);
        fprintf(out,"\n");
    }

}
