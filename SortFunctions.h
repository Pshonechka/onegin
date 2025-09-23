#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

int comparator (char *str1, char *str2);
int comparator_reverse (char *str1, char *str2);
int skip_to_alpha (char *str, int l, int x);
int skip_rev (char *str, int l, int x);
void my_sort (struct info *Onegin, int (* my_compare)(const void *, const void *));

#endif // SORTFUNCTIONS_H
