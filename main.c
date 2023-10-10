#include <ncurses.h>
#include <unistd.h>

int main() {
    initscr(); // Initialize ncurses
    noecho(); // Disable echoing of typed characters
    curs_set(FALSE); // Hide the cursor

    char* text = "My name is Jeff lmaooooooooooooooo";
    
    for (int i = 0; text[i] != '\0'; i++) {
        addch(text[i]); // Print the character
        refresh(); // Refresh the screen
        napms(30); // Delay for 100 milliseconds (adjust as needed)
    }

    getch(); // Wait for user input
    endwin(); // Cleanup ncurses
    return 0;
}

