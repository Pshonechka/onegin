#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "InputFunctions.h"


void opening_file(struct info *Onegin) {
    FILE *fp = fopen("emoboy.txt", "rb");
    if (fp == 0) {
        printf("Error in opening file");
        break;
    }
    Onegin -> text = fp;
}

char *get_arr(struct info *Onegin) {
    symbols_num = Onegin -> symbols_count;
    FILE *fp = Onegin -> *text;
    char *ptr = (char*) calloc(symbols_num + 1, sizeof(char));
    if (ptr == NULL) {
        printf("Error in creating array\n");
        return NULL;
    }

    size_t read_size =  fread(ptr, sizeof(char), symbols_num, fp);
    if (read_size != (size_t) symbols_num) {
        printf("Array sizes aren't equal\n");
        return NULL;//todo
    }
    ptr[symbols_num] = '\0';
    return ptr;
}

void fill_pointer_arr(char *from, char ** array_of_ptr, struct info *Onegin) {
    array_of_ptr[0] = from;
    int x = 0;
    for (int i = 0; i < symbols_num-1; i++) {
        if (from[i] == '\n') {
            x++;
            if (x < str_count) {
                array_of_ptr[x] = from+i+1;
            }
            else {
                printf("number of lines is bigger then number of ptrs!!!! FIX RN!!!!\n");
                exit(1);
                break;
            }
        }
    }
    Onegin -> array_of_pointers = array_of_ptr;
}

