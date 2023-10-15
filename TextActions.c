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
        if (cols == (left_margin) && text[i] == ' ') {
                while(text[i] == ' '){
                    i++;
                } 
        }
        if (cols >= right_margin && cols <= (right_margin + 5)) {
            if (text[i] == ' ') {
                addch('\n');
                move(getcury(stdscr) + 1, left_margin - 1);
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

void type_options(char** options, int num_options){
    int max_y, max_x;
    int rows = 5;
    getmaxyx(stdscr, max_y, max_x);
    max_y = 0; //Temporary, gets rid of warning
    
    for (int i = 0; i < num_options; i++) {
        move(rows, 25);
        add_option_nums(i, true);

        for (int j = 0; options[i][j] != '\0'; j++) {
            addch(options[i][j]);
            refresh(); 
            napms(30);
        }
        napms(350);
        rows += 1;
    }
    
    get_selected_option(options, num_options);
}

int get_selected_option(char** options, int num_options){
    int selected = 0;
    keypad(stdscr, TRUE);
    while(1){
        clear();
        int rows = 5;
        for (int i = 0; i < num_options; i++) {
            if (i == selected) {
                attron(A_REVERSE); 
            }
            move(rows, 25);
            add_option_nums(i, false);
            addstr(options[i]);
            if (i == selected) {
                attroff(A_REVERSE);
            }
            rows++;
        }

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                selected = (selected - 1 + num_options) % num_options;
                break;
            case KEY_DOWN:
                selected = (selected + 1) % num_options;
                break;
            case 10: // Enter key
                keypad(stdscr, FALSE);
                return selected + 1;     
        }
        refresh();
    }
    return 0;
    
}

void add_option_nums(int i, bool delay){
    if (delay){
        addch(i + 1 + '0');
        refresh(); 
        napms(50);
        addch(':');
        refresh(); 
        napms(50);
        addch(' ');
        refresh(); 
        napms(50);
    } 
    else {
        addch(i + 1 + '0');
        addch(':');
        addch(' ');
    }
    
}
