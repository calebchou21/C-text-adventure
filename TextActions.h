#ifndef TextActions_h
#define TextActions_h

#include <ncurses.h>
#include <unistd.h>

void type_text(char* text);
void type_options(char* options[]);
void screen_setup(void);
void screen_cleanup(void);

#endif  
