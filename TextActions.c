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
    int max_y, max_x;
    int cols = 25;
    getmaxyx(stdscr, max_y, max_x);
    printf("%d\n", max_y);
    printf("%d\n", max_x);
    move(5, 25);

    for (int i = 0; text[i] != '\0'; i++) {
        if (cols >= max_x - 30) {
            addch('\n');
            move(getcury(stdscr) + 1, 25);
            cols = 25;
        }else{
            addch(text[i]);
            cols++;
            refresh(); 
            napms(15);
        }
    }
    getch();
}
