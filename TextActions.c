#include <ncurses.h>
#include <unistd.h>
#include "TextActions.h"


void type_text(char* text) {
    move(5,10);
    for (int i = 0; text[i] != '\0'; i++) {
        addch(text[i]); 
        refresh(); 
        napms(50); 
   } 
}
