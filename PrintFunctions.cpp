#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "PrintFunctions.h"

void printf_str(const char* str) {
    for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        putchar(str[i]); // fputc(str[i], stream)
    }
    putchar('\n');
}


void put_str(const char* str, struct info *Onegin) {
    FILE* fp = Onegin -> ans;
    for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        fputc(str[i], fp); // fputc(str[i], stream)
    }
    fputc('\n', fp);
}

void print_text(struct info *Onegin) {
    char** array = Onegin -> array_of_pointers;
    int str_count = Onegin -> lines_count;
    for (int i = 0; i < str_count; i++) {
        printf("line %d: ", i);
        printf_str(array[i]); // my_fputs(array[i], stream)
    }
}

void put_text(struct info *Onegin) {
    assert(Onegin != NULL);
    assert(Onegin->array_of_pointers != NULL);

    char** array = Onegin -> array_of_pointers;
    int str_count = Onegin -> lines_count;
    for (int i = 0; i < str_count; i++) {
        put_str(array[i], Onegin); // my_fputs(array[i], stream)
    }

}
