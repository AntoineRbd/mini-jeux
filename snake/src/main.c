#include "snake.h"

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char * argv []) {
    int key = 0;
    int fail = 0;
    Snake snake = create_snake();
    Direction direction = {0,1};
    int Eat = 1;
    int eat_cell_number = 0;
    int delay = 0;

    int line_number = 0;
    int column_number = 0;
    char **grid = NULL;

    int easy_mode = 0;

    int opt;

    int d_time = 101;
    int d_limit = 60;

    // Help option
    while ((opt = getopt(argc, argv, "hEH")) != -1) {
        switch (opt) {
        case 'h': 
            printf("Choose your dificulty !\n");
            printf("    -E: Easy difficulty\n");
            printf("    -H: Hard difficulty\n");
            exit(EXIT_SUCCESS);
        case 'E': 
            easy_mode = 1;
            break;
        case 'H': 
            d_time = 40;
            d_limit = 20;
            break;
        default:
            fprintf(stderr, "Usage: %s [-hEH]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();

    getmaxyx(stdscr, line_number, column_number);

    grid = malloc(line_number * sizeof(char *));

    for (int i = 0; i < line_number; i++) {
        grid[i] = malloc(column_number * sizeof(char));
    }

    grid_init(line_number, column_number, grid);

    while (!fail) {
        if (Eat){
            eat_item(grid, line_number, column_number);
            eat_cell_number ++;
            delay = d_time - eat_cell_number;
            delay = (delay < d_limit) ? d_limit : delay;
            timeout(delay);
        }
        grid_print(snake, line_number, column_number, grid);
        key = getch();
        event_handle(&snake, key, &fail, &direction, &Eat, line_number, column_number, grid, easy_mode);
        erase();
    }
    
    timeout(5000);
    erase();
    print_fail(line_number, column_number);
    getch();

    endwin();
    return 0;
}
