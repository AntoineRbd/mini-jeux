#ifndef SNAKE_H
#define SNAKE_H

#define SNAKE_BODY '-'
#define SNAKE_HEAD '0'
#define ITEM_TO_EAT '*'
#define EMPTY_CELL ' '

#include <stddef.h>

struct Cell {
  int line;
  int column;
  struct Cell *next;
};
typedef struct Cell Cell;

struct Snake {
  Cell *Snake_head;
  Cell *Snake_queue;
};
typedef struct Snake Snake;

struct Direction {
  int line;
  int column;
};
typedef struct Direction Direction;

Snake create_snake(void);
void play_snake(Snake *snake, int line, int column, int *Eat, int *fail, int line_number, int column_number, char **grid, int easy_mode);
void delete_queue(Snake *snake, char **grid);
void grid_init(int line_number, int column_number, char **grid);
void grid_print(Snake snake, int line_number, int column_number, char **grid);
void event_handle(Snake *snake, int key, int *fail, Direction *direction, int *Eat, int line_number, int column_number, char **grid, int easy_mode);
void eat_item(char **grid, int line_number, int column_number);
void print_fail(int line_number, int column_number);



#endif /* SNAKE_H */
