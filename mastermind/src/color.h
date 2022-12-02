#ifndef COLOR_H
#define COLOR_H

typedef enum {
    RED,
    BLUE,
    GREEN,
    YELLOW,
} color_t;

struct secret_code {
    color_t color1;
    color_t color2;
    color_t color3;
    color_t color4;
};

struct secret_code secret_code_generator(void);
void print_secret_code(struct secret_code sc);
void print_player_code(struct secret_code sc);
#endif /* COLOR_H */
