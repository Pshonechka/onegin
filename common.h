#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>

//struct
struct info {
    FILE *text;
    char *buffer;
    char ** array_of_pointers;
    int lines_count;
    int symbols_count;
    FILE *ans;
};



#endif // COMMON_H
