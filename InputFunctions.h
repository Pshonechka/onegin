#ifndef INPUTFUNCTIONS_H
#define INPUTFUNCTIONS_H

void constructor_of_struct(struct info *Onegin);
void read_text(struct info *Onegin);
void parse_text(struct info *Onegin);
void destructor_of_struct(struct info *text_sorted, struct info *text_sorted_from_end);
int opening_file(FILE **to, const char* file_name, const char* method);
char *get_arr(struct info *Onegin);
void fill_pointer_arr(struct info *Onegin);

#endif // INPUTFUNCTIONS_H
