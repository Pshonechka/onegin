#ifndef COMMON_H
#define COMMON_H

struct info {
    FILE *text;
    char *buffer;
    char ** array_of_pointers;
    size_t lines_count;
    size_t symbols_count;
    FILE *ans;
};

#endif // COMMON_H
