#include "common.h"
#include "InputFunctions.h"
#include "PrintFunctions.h"
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
    struct info text_sorted = {.text = NULL, .buffer = NULL, .array_of_pointers = NULL, .lines_count = 0, .symbols_count = 0, .ans = NULL};
    struct info text_sorted_from_end = {.text = NULL, .buffer = NULL, .array_of_pointers = NULL, .lines_count = 0, .symbols_count = 0, .ans = NULL};
    opening_file(&text_sorted);
    // fseek()
    opening_file(&text_sorted_from_end);
    FILE *output = fopen("answers.txt", "wb");
    if (output == 0) {
        printf("Error in opening file");
    }
    text_sorted.ans = output;
    text_sorted_from_end.ans = output;
    ///FILE *fp = opening_file();
    /*FILE *fp = fopen("emoboy.txt", "rb");
    if (fp == 0) {
        printf("Error in opening file");
        return 0;
    }*/
    size_file (&text_sorted);
    size_file (&text_sorted_from_end);

    //printf("file size: %d\n", symbols_num);
    char *book = get_arr(&text_sorted);
    text_sorted.buffer = book;
    text_sorted_from_end.buffer = book;
    num_str (&text_sorted);
    num_str (&text_sorted_from_end);
    int str_count = text_sorted.lines_count;
    text_sorted.array_of_pointers = (char**) calloc((str_count+1), sizeof(char*));
    text_sorted_from_end.array_of_pointers = (char**) calloc((str_count+1), sizeof(char*));
    fill_pointer_arr(&text_sorted);
    fill_pointer_arr(&text_sorted_from_end);
    // put_text(&text_sorted_from_end);

    //print_text (&text_sorted_from_end);
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

    printf("printing arrays after sorting by start\n");
    // my_sort (&text_sorted, comparator);

    qsort(text_sorted.array_of_pointers, text_sorted.lines_count, sizeof(char *), comparator);


    put_text(&text_sorted);

    printf("printing arrays after sorting by end\n");
    //my_sort (&text_sorted_from_end, comparator_reverse);
    qsort (text_sorted_from_end.array_of_pointers, str_count, sizeof(char *), comparator_reverse);
    put_text (&text_sorted_from_end);
    fputc('\n', output);
    fputs(text_sorted.buffer, output);
    free (text_sorted_from_end.array_of_pointers);
    free (text_sorted.array_of_pointers);
}

