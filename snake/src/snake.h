#ifndef SNAKE_H
#define SNAKE_H

#define SNAKE_BODY '-'
#define SNAKE_HEAD '0'
#define ITEM_TO_EAT '*'
#define EMPTY_CELL ' '

#include <stddef.h>

 // Global variables
char **grid = NULL;
int line_number = 0;
int column_number = 0;


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
void play_snake(Snake *snake, int line, int column, int *Eat, int *fail);
void delete_queue(Snake *snake);
void grid_init(void);
void grid_print(Snake snake);
void event_handle(Snake *snake, int key, int *fail, Direction *direction, int *Eat);
void eat_item(char **grid);
void print_fail(void);



#endif /* SNAKE_H */
