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


void type_text(char* text, bool clear_screen, bool refresh) {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x); 
    int left_margin = max_x / 9;
    int right_margin = max_x - left_margin - 5;
    int cols = left_margin;

    move(5, left_margin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (cols >= right_margin && cols <= (right_margin + 5)) {
            if (text[i] == ' ') {
                while (text[i] == ' ')
                    ++i;
                addch('\n');
                move(getcury(stdscr) + 1, left_margin);
                cols = left_margin - 1;
                while (text[i] == ' ')
                    i++;
            }
        } else if (cols > (right_margin + 5)){
            while(text[i] == '\"' || text[i] == '\'' || text[i] == '.' || text[i] == ',' || text[i] == '?') {
                addch(text[i]);
                i++;
            }
            if (text[i] != ' '){
                addch('-');
            }
            addch('\n');
            move(getcury(stdscr) + 1, left_margin);
            cols = left_margin - 1;
            while (text[i] == ' ')
                i++;
        }
        addch(text[i]);
        cols++;
        refresh(); 
        if (refresh == true)
            napms(15);
    }
    getch();
    if (clear_screen) {
        clear();
        refresh();
    }
    
}


void type_options(char** options, int num_options){
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    int rows = 5;
    int left_margin = max_x / 9;
    int cursor_y = getcury(stdscr);
    
    for (int i = 0; i < num_options; i++) {
        move(cursor_y+1, left_margin);
        add_option_nums(i, true);

        for (int j = 0; options[i][j] != '\0'; j++) {
            addch(options[i][j]);
            refresh(); 
            napms(30);
        }
        napms(350);
        rows += 1;
        cursor_y += 1;
    }
    char* text = "This is a second test case!\n";
    get_selected_option(options, text, num_options);
}

int get_selected_option(char** options, char* text, int num_options){
    int selected = 0;
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    int left_margin = max_x / 9;
    keypad(stdscr, TRUE);
    int cursor_y = getcury(stdscr);
    type_text(text, false, false);
    while(1){
        clear();
        
        int rows = 5;
        for (int i = 0; i < num_options; i++) {
            if (i == selected) {
                attron(A_REVERSE); 
            }
            move(cursor_y+1, left_margin);
            add_option_nums(i, false);
            addstr(options[i]);
            if (i == selected) {
                attroff(A_REVERSE);
            }
            rows++;
            cursor_y += 1;
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
    return selected;
    
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
