#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

int Comparator (char *str1, char *str2);
int ComparatorReverse (char *str1, char *str2);
int skip_to_alpha (char *str, int l, int x);
int skip_rev (char *str, int l, int x);
void My_Sort (struct info *Onegin, int (* MyCompare)(const void *, const void *));

#endif // SORTFUNCTIONS_H
