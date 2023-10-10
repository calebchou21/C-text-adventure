#include <ncurses.h>
#include <unistd.h>
#include "TextActions.h"

void screen_setup(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE); 
}

void screen_cleanup(void) {
    getch();
    endwin();
}

void type_text(char* text) {
    for (int i = 0; text[i] != '\0'; i++) {
        addch(text[i]); 
        refresh(); 
        napms(50); 
    }
    getch();
}
