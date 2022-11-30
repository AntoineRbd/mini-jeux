#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef enum {
    RED,
    BLUE,
    GREEN,
    YELLOW,
} color;

struct secret_code {
    color color1;
    color color2;
    color color3;
    color color4;
};

struct secret_code secret_code_generator(void);
void print_secret_code(struct secret_code sc);
void print_player_code(struct secret_code sc);
