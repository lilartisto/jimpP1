#ifndef PRINTFILE_H
#define PRINTFILE_H

#include <stdio.h>
#include "map.h"

void writeState(StateT* state ,FILE* out);
void writeStateToPBM(StateT* state , int i);

#endif