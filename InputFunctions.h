#ifndef INPUTFUNCTIONS_H
#define INPUTFUNCTIONS_H

void constructor_of_struct(struct info *text_sorted, struct info *text_sorted_from_end);
void destructor_of_struct(struct info *text_sorted, struct info *text_sorted_from_end);
void opening_file(struct info *Onegin);
char *get_arr(struct info *Onegin);
void fill_pointer_arr(struct info *Onegin);

#endif // INPUTFUNCTIONS_H
