#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>

#include "common.h"
#include "InputFunctions.h"
#include "Printfunctions.h"
#include "SizeFunctions.h"
#include "SortFunctions.h"

//struct OneginInfo {
// FILE* 8byte
// char* 8byte
// char** 8byte
// size_t n_strings 8byte
//}

/*
Constructor of struct
ReadFileToBuffer
FillStringArray1
FillStringArray2
Sort(cmp1)
Sort(cmp2)
qsort(cmp1)
qsort(cmp2)
Destructor of struct
*/

int main() {
    struct info text_sorted = {.text = NULL, .array_of_pointers = NULL, .lines_count = 0, .symbols_count = 0};
    struct info text_sorted_from_end = {.text = NULL, .array_of_pointers = NULL, .lines_count = 0, .symbols_count = 0};
    opening_file(&text_sorted);
    opening_file(&text_sorted_from_end);
    ///FILE *fp = opening_file();
    /*FILE *fp = fopen("emoboy.txt", "rb");
    if (fp == 0) {
        printf("Error in opening file");
        return 0;
    }*/
    size_file (&text_sorted);
    size_file (&text_sorted_from_end);

    //printf("file size: %d\n", symbols_num);
    char *book  = get_arr(&text_sorted);

    //printf("text:\n %s\n", book);
    //[a][b][c]['\n'][f][g]['\0']
    //[0x100][0x200][0x300][0]
    //todo: function
    num_str (book, &text_sorted);
    num_str (book, &text_sorted_from_end);
    int str_count = text_sorted.lines_count;
    char **ptrs_from_start = (char**) calloc((str_count+1), sizeof(char*));
    char **ptrs_from_end = (char**) calloc((str_count+1), sizeof(char*));
    fill_pointer_arr(book, ptrs_from_start, &text_sorted);
    fill_pointer_arr(book, ptrs_from_end, &text_sorted_from_end);
       // printf("%p", book[0]);
    //printf("printing ptrs before parsing:\n");
     //book[0] === *(book + i), &(book+i)
    //printf("%c\n", book[0]);
   // printf("%p\n", array_of_ptr[0]);
    /*for (int i = 0; i < str_count; i++) {
        printf ("%p\n", array_of_ptr[i]);
    }*/




   /// printf("kolychestvo strok: %d\n", str_count);
  ///  printf("kolychestvo bukv: %d\n", symbols_num);
    /*printf("printing ptrs after parsing\n");
    for (int i = 0; i < str_count; i++) {
        printf ("ptr %d: %p\n", i, array_of_ptr[i]);
    }*/

   // print_text(array_of_ptr, symbols_num);
    //printf("printing arrays after sorting by start\n");
    My_Sort (&text_sorted, Comparator);
    print_text (&text_sorted, str_count);
    //printf("printing arrays after sorting by end\n");
    //char **array_reversed = My_Sort (array_of_ptr, str_count, ComparatorReverse);
    //print_text (array_reversed, str_count);
    //FILE *answers = fopen("answers.txt", "wb");
    //TODO: naming,
    /*fwrite(array_sorted, sizeof(char), str_count, answers);
    fwrite(array_reversed, sizeof(char*), str_count, answers);
    printf("end");*/
    //print_text (array_reversed, str_count);*/
  //  strcpy_1(str1, str2);
    free (book);
    free (text_sorted.array_of_pointers);
}

