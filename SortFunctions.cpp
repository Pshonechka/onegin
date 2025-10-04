#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "common.h"
#include "SortFunctions.h"
#include "SizeFunctions.h"


int comparator (const void *par1, const void *par2) {
    assert(par1 != NULL);
    assert(par2 != NULL);

    const char * str1 = *(const char * const*) par1;
    const char * str2 = *(const char * const*) par2;
    int l1 = my_strlen(str1);
    int l2 =  my_strlen(str2);
    int minl = min_num(l1,l2);
    int i1 = 0, i2 = 0;
    while (i1 < minl && i2 < minl) {
        int k1 = skip_to_alpha(str1, l1, i1);
        int k2 = skip_to_alpha(str2, l2, i2);
        i1 += k1;
        i2 += k2;
        int s1 = tolower(str1[i1]);
        int s2 = tolower(str2[i2]);
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
}

int comparator_reverse (const void *par1, const void *par2) {
    const char *str1 =  *(const char * const*) par1;
    const char *str2 =  *(const char * const*) par2;
    int l1 = my_strlen(str1);
    int l2 = my_strlen(str2);
    printf("meow");
    int minl = min_num(l1,l2);
    int i1 = l1;
    int i2 = l2;
    printf("meow");
    while (i1 > 0 && i2 > 0) {

        int k1 = skip_rev(str1, i1);
        int k2 = skip_rev(str2, i2);
        i1 -= k1;
        i2 -= k2;
        int s1 = tolower(str1[i1]);
        int s2 = tolower(str2[i2]);
        if (s1 < s2) {
            return -1;
        }
        else if (s1 > s2) {
            return 1;
        }
        i1--;
        i2--;
        minl--;
    }
    return 0;
}


int skip_to_alpha(const char *str, int l, int x) {
    if (isalpha(str[x]) != 0) {
        return 0;
    }
    int c = 0;
    int i = x;
    while (isalpha(str[i]) == 0 && i < l) {
        c++;
        i++;
    }
    return c;
}

int skip_rev(const char *str, int x) {
    if (isalpha(str[x]) != 0) {
            return 0;
    }
    int c = 0;
    int i = x;
    while (isalpha(str[i]) == 0 && i>0) {
        c++;
        i--;
    }
    return c;
}



void my_sort (struct info *Onegin, int (* my_compare)(const void *, const void *)) {
    char **array_of_ptr = Onegin -> array_of_pointers;
    int str_count = Onegin -> lines_count;
    int i = 0, j = 0;
    for (i = 0; i < str_count - 1; i++) {
        for (j = 0; j < str_count - 1 - i; j++) {
            if (my_compare(array_of_ptr[j], array_of_ptr[j+1]) > 0) {
                printf("meow");
                char *c = array_of_ptr[j];
                array_of_ptr[j] = array_of_ptr[j+1];
                array_of_ptr[j+1] = c;
            }
        }
    }
    printf("meow");
}

