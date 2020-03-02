#include "printFile.h"
#include <stdio.h>

void writeState(StateT* state, FILE* out)
{
    for (int i = 1; i < state->height+1; i++)
    {
        for (int j = 1; j < state->width+1; j++)
            fprintf(out, "%d ", state->board[i][j]);
        fprintf(out,"\n");
    }
}

void writeStateToPBM(StateT* state, int i)
{
    char tab[32];
    sprintf( tab, "photo%d.pbm", i );
    FILE* out = fopen(tab,"w");

    if( out == NULL )
        return;
    
    fprintf( out, "P1\n%d %d\n", state->width, state->height);
    writeState( state, out );
    fclose( out );
}