#include "snake.h"

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

// Snake Creattion
Snake create_snake(void) {

    Snake snake;

    Cell *snake_head = malloc(sizeof(Cell));
    Cell *snake_queue = malloc(sizeof(Cell));
    Cell *snake_body = malloc(sizeof(Cell));

    snake_head->line = 1;
    snake_head->column = 4;
    snake_head->next = NULL;

    snake_body->line = 1;
    snake_body->column = 3;
    snake_body->next = snake_head;

    snake_queue->line = 1;
    snake_queue->column = 2;
    snake_queue->next = snake_body;

    snake.Snake_head = snake_head;
    snake.Snake_queue = snake_queue;

    return snake;
}

void play_snake(Snake *snake, int line, int column, int *Eat, int *fail, int line_number, int column_number, char **grid, int easy_mode) {
    Cell *new_head = malloc(sizeof(Cell));

    new_head->line = line;
    new_head->column = column;
    new_head->next = NULL;

    snake->Snake_head->next = new_head;
    grid[(snake->Snake_head->line)][(snake->Snake_head->column)] = SNAKE_BODY;
    snake->Snake_head = snake->Snake_head->next;

    if (easy_mode == 1) {
    if (snake->Snake_head->line < 0) {
      snake->Snake_head->line = line_number - 1;
    }

    else if (snake->Snake_head->line > line_number-1) {
      snake->Snake_head->line = 0;
    }
    else if (snake->Snake_head->column < 0) {
      snake->Snake_head->column = column_number - 1;
    }
    else if (snake->Snake_head->column > column_number - 1) {
      snake->Snake_head->column = 0;
    }
    else if (grid[snake->Snake_head->line][snake->Snake_head->column] == SNAKE_BODY) {
      *fail = 1;
    }
  }

    if (snake->Snake_head->line < 0 ||
            snake->Snake_head->line > line_number - 1 ||
            snake->Snake_head->column < 0 ||
            snake->Snake_head->column > column_number - 1)
        *fail = 1;

    if (!*fail) {
        *Eat = (grid[snake->Snake_head->line][snake->Snake_head->column] == ITEM_TO_EAT) ? 1 : 0;
        grid[snake->Snake_head->line][snake->Snake_head->column] = SNAKE_HEAD;
    }
}

void delete_queue(Snake *snake, char **grid) {
    Cell *auxi;

    auxi = snake->Snake_queue;
    grid[snake->Snake_queue->line][snake->Snake_queue->column] = EMPTY_CELL;
    snake->Snake_queue = snake->Snake_queue->next;
    free(auxi);
}

void grid_init(int line_number, int column_number, char **grid) {
    for (int i = 0; i < line_number; i++) {
        for (int j = 0; j < column_number; j++) {
            grid[i][j] = EMPTY_CELL;
        }
    }
}

void grid_print(Snake snake, int line_number, int column_number, char **grid) {
    for (int i = 0; i < line_number; i++) {
        for (int j = 0; j < column_number; j++) {
            printw("%c",grid[i][j]);
        }
    }
}

void event_handle(Snake *snake, int key, int *fail, Direction *direction, int *Eat, int line_number, int column_number, char **grid, int easy_mode) {
    if (direction->line == 0) {
        if (key == KEY_UP){
            direction->line = -1;
            direction->column = 0;
        }

        if (key == KEY_DOWN) {
            direction->line = 1;
            direction->column = 0;
        }
    }

    if (direction->column == 0) {
        if (key == KEY_LEFT) {
            direction->column = -1;
            direction->line = 0;
        }
        if (key == KEY_RIGHT) {
            direction->column = 1;
            direction->line = 0;
        }
    }

    play_snake(snake, snake->Snake_head->line + direction->line, snake->Snake_head->column + direction->column, Eat, fail, line_number, column_number, grid, easy_mode);
    if(!*Eat)
        delete_queue(snake, grid);
}

void eat_item(char **grid, int line_number, int column_number) {
    int line = 0;
    int column = 0;
    int done = 0;

    srand(time(NULL));

    while (!done){
        line = rand() % (line_number - 1);
        column = rand() % (column_number - 1);

        if(grid[line][column] == EMPTY_CELL) {
            grid[line][column] = ITEM_TO_EAT;
            done = 1;
        }
    }
}

void print_fail(int line_number, int column_number) {
    move(line_number / 2 - 5 / 2, column_number / 2 - 37 / 2);
    printw("    _/_/_/_/    _/_/    _/_/_/  _/   \n");

    move(1 + line_number / 2 - 5 / 2, column_number / 2 - 37 / 2);
    printw("   _/        _/    _/    _/    _/    \n");

    move(2 + line_number / 2 - 5 / 2, column_number / 2 - 37 / 2);
    printw("  _/_/_/    _/_/_/_/    _/    _/     \n");

    move(3 + line_number / 2 - 5 / 2, column_number / 2 - 37 / 2);
    printw(" _/        _/    _/    _/    _/      \n");

    move(4 + line_number / 2 - 5 / 2, column_number / 2 - 37 / 2);
    printw("_/        _/    _/  _/_/_/  _/_/_/_/ \n");
}
