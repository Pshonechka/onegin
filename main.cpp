//#include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "InputFunctions.h"
#include "PrintFunctions.h"
#include "SizeFunctions.h"
#include "SortFunctions.h"

int main() {
    struct info text_sorted = {};

    constructor_of_struct(&text_sorted);

    qsort(text_sorted.array_of_pointers, text_sorted.lines_count, sizeof(char *), comparator);
    put_text(&text_sorted);

    my_sort (&text_sorted, comparator_reverse);
    put_text (&text_sorted);

    fputs(text_sorted.buffer, text_sorted.ans);

    destructor_of_struct(&text_sorted);
}
