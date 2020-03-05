#ifndef PRINTFILE_H
#define PRINTFILE_H

#include <stdio.h>
#include <png.h>
#include "map.h"

void writeState(StateT* state ,FILE* out);
void writeStateToPNG(StateT* state, char* tab);

void write_png_file(char* file_name);
void process_file( StateT* state );

#endif
