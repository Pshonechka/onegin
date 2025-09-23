#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "SizeFunctions.h"

void size_file (struct info *Onegin) {
    FILE *fp = Onegin -> *text;
    fseek(fp, 0L, SEEK_END);
    int symbols_count = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    Onegin->symbols_count = symbols_count;
}

void num_str (char *arr, struct info *Onegin) {
    int symbols_num = Onegin -> symbols_count;
    int str_count = 0;
    for (int i = 0; i < symbols_num; i++) {
       if (arr[i] == '\n') {
            str_count += 1;
       }
    }
    Onegin->lines_count = str_count;
}

int strlen_1 (char *str) {
int c = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        c++;
    }
    return c;
}

int min(int a, int b) {
    return a < b ?  a : b;
}
