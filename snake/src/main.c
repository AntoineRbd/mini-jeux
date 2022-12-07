#include "snake.h"

#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

int main(void) {
    int key = 0;
    int fail = 0;
    Snake snake = create_snake();
    Direction direction = {0,1};
    int Eat = 1;
    int eat_cell_number = 0;
    int delay = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();

    getmaxyx(stdscr, line_number, column_number);

    grid = malloc(line_number * sizeof(char *));

    for (int i = 0; i < line_number; i++) {
        grid[i] = malloc(column_number * sizeof(char));
    }

    grid_init();

    while (!fail) {
        if (Eat){
            eat_item(grid);
            eat_cell_number ++;
            delay = 101 - eat_cell_number;
            delay = (delay < 60) ? 60 : delay;
            timeout(delay);
        }
        grid_print(snake);
        key = getch();
        event_handle(&snake, key, &fail, &direction, &Eat);
        erase();
    }

    timeout(5000);
    erase();
    print_fail();
    getch();

    endwin();
    return 0;
}
