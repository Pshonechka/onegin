#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

int comparator (const void *str1, const void *str2);
int comparator_reverse (const void *str1, const void *str2);
int skip_to_alpha (const char *str, int l, int x);
int skip_rev (const char *str, int x);
void my_sort (struct info *Onegin, int (* my_compare)(const void *, const void *));

#endif // SORTFUNCTIONS_H
