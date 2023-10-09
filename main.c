#include <ncurses.h>
#include <stdlib.h>

int main() {
    initscr(); // Initialize ncurses
    raw(); // Disable line buffering
    keypad(stdscr, TRUE); // Enable keypad (for arrow keys)
    noecho(); // Disable echoing of typed characters

    int selected = 0;
    char* options[] = {"Go to the town", "Eat at the restaurant", "Exit"};
    int numOptions = sizeof(options) / sizeof(options[0]);

    while (1) {
        clear(); // Clear the screen

        // Display options
        for (int i = 0; i < numOptions; i++) {
            if (i == selected) {
                attron(A_REVERSE); // Highlight the selected option
            }
            mvprintw(i, 0, options[i]);
            attroff(A_REVERSE);
        }

        // Get user input
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                selected = (selected - 1 + numOptions) % numOptions;
                break;
            case KEY_DOWN:
                selected = (selected + 1) % numOptions;
                break;
            case 10: // Enter key
                if (selected == numOptions - 1) {
                    // Exit the program if "Exit" is selected
                    endwin(); // Cleanup ncurses
                    exit(0);
                } else {
                    // Process the selected option here
                    mvprintw(numOptions + 1, 0, "Selected: %s", options[selected]);
                }
                break;
        }

        refresh(); // Refresh the screen
    }

    endwin(); // Cleanup ncurses
    return 0;
}

