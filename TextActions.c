#include <ncurses.h>
#include <unistd.h>

void type_text(char* text) {
    for (int i = 0; text[i] != '\0'; i++) {
        addch(text[i]); 
        refresh(); 
        napms(50); 
   } 
}
