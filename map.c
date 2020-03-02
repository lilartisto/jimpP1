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

void fileToState(StateT* state, FILE* in)
{
    int x, y;
    while( fscanf( in, "%d %d", &x, &y) != EOF )
    {
        if( x >= 1 && x <= state->width && y >= 1 && y <= state->height )
            state->board[y][x] = 1;
    }
}

int StateToFile( StateT* state, char* name )
{
    FILE* out = fopen(name, "w");
    if( out == NULL )
        return 1;

    fprintf( out, "%d %d\n", state->width, state->height );

    for( int i = 1; i <= state->height; i++ )
        for( int j = 1; j <= state->width; j++ )
            if( state->board[i][j] == 1 )
                fprintf( out, "%d %d\n", j, i );
    return 0;
}