#include <stdbool.h>
#include <stdio.h>



typedef struct State
{
    bool **board;
    int width;
    int height;
}StateT;

void initState(StateT* state,int width,int height);
void freeState(StateT* state);
void writeState(StateT* state ,FILE* out);
