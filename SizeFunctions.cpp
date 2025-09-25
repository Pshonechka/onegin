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

int strlen_1 (const char *str) {
    assert(str != NULL);
    ///fprintf(stderr, "str = %s\n", str);
    int i = 0;
    assert(str != NULL);
    ///fprintf(stderr, "p_str = %p\n", str);
    while (str[i] != '\0' && str[i] != '\n') {
        assert(str != NULL);
        ///fprintf(stderr, "str = %p\n", str);
        ///fprintf(stderr, "str[%d] = %c\n", i, str[i]);
        i++;
    }
    return i;
}

int min(int a, int b) {
    return a < b ? a : b;
}
