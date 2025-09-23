#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "PrintFunctions.h"

void printf_str(char* str) {
    for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        putchar(str[i]); // fputc(str[i], stream)
    }
    putchar('\n');
}

void print_text(struct info *Onegin, int str_count) {
    char** array = Onegin->array_of_pointers;
    for (int i = 0; i < str_count; i++) {
        printf("line %d: ", i);
        printf_str(array[i]); // my_fputs(array[i], stream)
    }
}
