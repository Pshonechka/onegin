#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "InputFunctions.h"
#include "SizeFunctions.h"

// read_file_and_parse
void constructor_of_struct(struct info *Onegin) {
    opening_file(&Onegin -> text, "oneginshort.txt", "rb");
    opening_file(&Onegin -> ans, "answers.txt", "wb");
    size_file (Onegin);
    read_text(Onegin);
    parse_text(Onegin);
}

void read_text(struct info *Onegin) {
    char *book = get_arr(Onegin);
    Onegin -> buffer = book;
    num_str (Onegin);
}

void parse_text(struct info *Onegin) {
    int str_count = Onegin -> lines_count;
    Onegin -> array_of_pointers = (char**) calloc((str_count+1), sizeof(char*));
    fill_pointer_arr(Onegin);
}

void destructor_of_struct(struct info *text_sorted) {
    free (text_sorted -> array_of_pointers);
}

int opening_file(FILE **to, const char* file_name, const char* method) {
    *to = fopen(file_name, method);
    if (*to == 0) {
        printf("Error in opening file");
        return 1;
    }
    return 0;
}

char *get_arr(struct info *Onegin) {
    int symbols_num = Onegin -> symbols_count;
    FILE *fp = Onegin -> text;
    char *ptr = (char*) calloc(symbols_num + 1, sizeof(char));
    if (ptr == NULL) {
        printf("Error in creating array\n");
        return NULL;
    }

    size_t read_size = fread(ptr, sizeof(char), symbols_num, fp);

    if (read_size != (size_t) symbols_num) {
        printf("read_size = %u\n", read_size);
        printf("symbols_num = %d\n", symbols_num);
        printf("Array sizes aren't equal\n");
        return NULL;
    }

    ptr[symbols_num] = '\0';
    return ptr;
}

void fill_pointer_arr(struct info *Onegin) {
    char ** array_of_ptr = Onegin -> array_of_pointers;
    char *from = Onegin -> buffer;
    array_of_ptr[0] = from;
    int symbols_num = Onegin -> symbols_count;
    int str_count = Onegin -> lines_count;
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
}

