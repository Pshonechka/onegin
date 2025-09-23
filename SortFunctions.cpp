#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "SortFunctions.h"
#include "SizeFunctions.h"

//TODO: Rewrite on void* and use qsort();

// int Comparator (const void* par1, const void* par2)
// char* str1 = *(char**) par1

int сomparator (const void *par1, const void *par2) {
    char *str1 = *(char**) par1;
    char *str2 = *(char**) par2;
    int l1 = strlen_1(str1);
    int l2 = strlen_1(str2);
    minl = min(l1,l2);
    int i1, i2 = 0;
    while (str1[i1] < minl && str2[i2] < minl) {
        k1 = skip_to_alpha(str1, l1, i1);
        k2 = skip_to_alpha(str2, l2, i2);
        s1 = tolower(str1[i1 + k1]);
        s2 = tolower(str1[i2 + k2]);
        if (s1 < s2) {
            return -1;
        }
        else if (s1 > s2) {
            return 1;
        }
        i1++;
        i2++;
    }
    return 0;
    // for/while ( i1++, i2++)
    // not alpha : i++
    // i1 - str1
    // i2 - str2
    /*for (int i = 0; i < min(l1, l2); i++) {
        char s1 = tolower(str1[i]);
        for (int x = 0; x < min(l1, l2); x++) {
            char s2 = tolower(str2[i]);
            if (isalpha(s2) == 0) { // str2[x]
                x++;
            }
            // s2 = ...
            else {
                if (s1 < s2) {
                    return -1;
                }
                else if (s1 > s2) {
                    return 1;
                }
                else if (s1 == s2) {
                    x++;
                    i++;
                }
            }
        }
    }
    return 0;*/
}

int сomparator_кeverse (const void *par1, const void *par2) {
    char *str1 = *(char**) par1;
    char *str2 = *(char**) par2;
    l1 = strlen_1(str1);
    l2 = strlen_1(str2);
    minl = min(l1,l2);
    int i1 = l1 - 1;
    int i2 = l2 - 1;
    while (minl > 0) {
        k1 = skip_rev(str1, l1, i1);
        k2 = skip_rev(str2, l2, i2);
        s1 = tolower(str1[i1 + k1]);
        s2 = tolower(str1[i2 + k2]);
        if (s1 < s2) {
            return -1;
        }
        else if (s1 > s2) {
            return 1;
        }
        i1--;
        i2--;
        min1--;
    }
    return 0;
}


int skip_to_alpha(char *str, int l, int x) { // в аргументы l1/l2
    if (isalpha(str[x]) != 0) {
            return 0;
    }
    int c = 0;
    for (int i = x; i < l; i++) { // l1/l2
        while (isalpha(str[i]) == 0) {
            c++;
        }
    }
    return c;
}

int skip_rev(char *str, int l, int x) { //  l длина х номер символа с конца
    if (isalpha(str[x]) != 0) {
            return 0;
    }
    for (i = x; i > 0; i--) {
        while (isalpha(str[i]) == 0) {
            c++;
        }
    }
    return c;
}

/*int ComparatorReverse (char *str1, char *str2) {
    int l1 = strlen_1(str1)-1;
    int l2 = strlen_1(str2)-1;
    while (l1 >= 0 && l2 >= 0) {
        if (let1[l1] == let2[l2]) {
            l1--;
            l2--;
        }
        else if (let1[l1] < let2[l2]) {
            return -1;
        }
        else if (let1[l1] > let2[l2]) {
            return 1;
        }
    }
    return 0;
}*/

/*char *letters_str (char *str1, int len) {
    char *array_with_letters = (char*) calloc(len, sizeof(char));
    int x = 0;
    for (int i = 0; i < len; i++) {
        int s1 = tolower(str1[i]);
        if (isalpha(s1) != 0) {
            array_with_letters[x] = s1;
            x++;
        }
    }
    return array_with_letters;
}*/

void my_sort (struct info *Onegin, int (* my_compare)(const void *, const void *)) {
    char **array_of_ptr = Onegin -> array_of_pointers;
    int str_count = Onegin -> lines_count;
    int i, j = 0;
    for (i = 1; i < str_count; i++) {
        for (j = 0; j < str_count - i; j++) {
          //  printf("%p\n", array_of_ptr[j]);
            //printf("%d", t);
            if (my_compare(array_of_ptr[j], array_of_ptr[j+1]) > 0) {
                char *c = array_of_ptr[j];
                array_of_ptr[j] = array_of_ptr[j+1];
                array_of_ptr[j+1] = c;
            }
        }
    }
    Onegin -> array_of_pointers = array_of_ptr;
}

