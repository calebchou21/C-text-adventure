#ifndef TextActions_h
#define TextActions_h

#include <ncurses.h>
#include <unistd.h>

void type_text(char* text, bool clear_screen, bool refresh);
void type_options(char** options, int num_options);
void add_option_nums(int i, bool delay);
void screen_setup(void);
void screen_cleanup(void);
int get_selected_option(char** options, char* text, int num_options);


#endif  
