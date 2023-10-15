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
    getmaxyx(stdscr, max_y, max_x); 
    int left_margin = max_x / 9;
    int right_margin = max_x - left_margin - 5;
    int cols = left_margin;

    move(5, left_margin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (cols == 25 && text[i] == ' ') {continue;}
        if (cols >= right_margin && cols <= (right_margin + 5)) {
            if (text[i] == ' ') {
                while(text[i] == ' '){
                    i++;
                }
                addch('\n');
                move(getcury(stdscr) + 1, left_margin);
                cols = left_margin;
            }
        } else if (cols > (right_margin + 5)){
            if (text[i] != ' '){
                addch('-');
            }
            addch('\n');
            move(getcury(stdscr) + 1, left_margin);
            cols = left_margin;
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

void type_options(char* options[]){

}
