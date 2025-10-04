#include <TXLib.h>
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
    struct info text_sorted_from_end = {};
    //constructor_of_struct(&text_sorted);
    constructor_of_struct(&text_sorted_from_end);

    //my_sort (&text_sorted, comparator);
    //qsort(text_sorted.array_of_pointers, text_sorted.lines_count, sizeof(char *), comparator);
    //put_text(&text_sorted);

    my_sort (&text_sorted_from_end, comparator_reverse);
    //qsort (text_sorted_from_end.array_of_pointers, text_sorted_from_end.lines_count, sizeof(char *), comparator_reverse);
    put_text (&text_sorted_from_end);

    //fputs(text_sorted.buffer, text_sorted.ans);

    destructor_of_struct(&text_sorted, &text_sorted_from_end);
}

