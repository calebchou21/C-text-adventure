#include "TextActions.h"

void screen_setup(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    scrollok(stdscr, TRUE);
}

void screen_cleanup(void) {
    getch();
    endwin();
}


void type_text(char* text) {
    int max_y, max_x;
    int cur_y;
    int cols = 25;
    getmaxyx(stdscr, max_y, max_x); 
    
    move(5, 25);
    for (int i = 0; text[i] != '\0'; i++) {
        if ((cols == (max_x-30-25) && text[i] == ' ') ||
            (cols == (max_x-30-25) && text[i] == ',') ||
            (cols == (max_x-30-25) && text[i] == '.')) {continue;}
        if (cols >= max_x - 30) {
            if (text[i - 1] != ' ')
                addch('-');
            addch('\n');
            move(getcury(stdscr) + 1, 25);
            cols = 25;
        }
            addch(text[i]);
            cols++;
            refresh(); 
            napms(15);
    }
    getch();
    clear();
    refresh();
}
