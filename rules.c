#include <stdio.h>
#include "rules.h"
#include <stdbool.h>
#include "neighborhood.h"
#include "map.h"

bool born_kill(StateT* state, int x, int y)
{
    //int n = count_neighborhood( state, x , y );
    int n = 4;

    if( n == 3 )
        return 1;
    else if( n == 2 && state->board[y][x] == 1 )
        return 1;
    else
        return 0;
}

void next_round( StateT* state1, StateT* state2)
{
    for( int i = 1; i <= state1->height; i++)
        for( int j = 1; j <= state1->width; j++)
        {
            if( born_kill(state1, j, i) )
                state2->board[i][j] = 1;
            else
                state2->board[i][j] = 0;
        }
}