#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "SizeFunctions.h"

void size_file (struct info *Onegin) {
    assert(Onegin);
    FILE *fp = Onegin -> text;
    fseek(fp, 0L, SEEK_END);
    int symbols_count = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    Onegin->symbols_count = symbols_count - 1;
}

void num_str (struct info *Onegin) {
    assert(Onegin);
    int symbols_num = Onegin -> symbols_count;
    char *arr = Onegin -> buffer;
    int str_count = 1;
    for (int i = 0; i < symbols_num; i++) {
       if (arr[i] == '\n') {
            str_count += 1;
       }
    }
    Onegin->lines_count = str_count;
}

int my_strlen (const char *str) {
    assert(str != NULL);
    int i = 0;
    assert(str != NULL);
    while (str[i] != '\0' && str[i] != '\n') {
        assert(str != NULL);
        i++;
    }
    return i;
}

int min_num(int a, int b) {
    return a < b ? a : b;
}
