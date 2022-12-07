#include "mastermind.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int *input_code(int *lpBuffer, size_t nBufSize)
{
    size_t nbCar = 0;
    int c;

    c = getchar();

    while (nbCar < nBufSize - 0 && c != EOF && c != '\n') {
        lpBuffer[nbCar] = c - '0';
        nbCar += 1;
        c = getchar();
    }

    return lpBuffer;
}

bool check_color_valid(struct secret_code pc) {
    bool color1_valid = false;
    bool color2_valid = false;
    bool color3_valid = false;
    bool color4_valid = false;

    if(0 <= pc.color1 && pc.color1 <= 3){
        color1_valid = true;
    }

    if(0 <= pc.color2 && pc.color2 <= 3){
        color2_valid = true;
    }

    if(0 <= pc.color3 && pc.color3 <= 3){
        color3_valid = true;
    }

    if(0 <= pc.color4 && pc.color4 <= 3){
        color4_valid = true;
    }

    return color1_valid && color2_valid && color3_valid && color4_valid;
}

static int count_color_RED_secret_code(struct secret_code sc) {
    int red_count = 0;

    if (sc.color1 == RED)
        red_count += 1;

    if (sc.color2 == RED)
        red_count += 1;

    if (sc.color3 == RED)
        red_count += 1;

    if (sc.color4 == RED)
        red_count += 1;

    return red_count;
}

static int count_color_BLUE_secret_code(struct secret_code sc) {
    int blue_count = 0;

    if (sc.color1 == BLUE)
        blue_count += 1;

    if (sc.color2 == BLUE)
        blue_count += 1;

    if (sc.color3 == BLUE)
        blue_count += 1;

    if (sc.color4 == BLUE)
        blue_count += 1;

    return blue_count;
}

static int count_color_GREEN_secret_code(struct secret_code sc) {
    int green_count = 0;

    if (sc.color1 == GREEN)
        green_count += 1;

    if (sc.color2 == GREEN)
        green_count += 1;

    if (sc.color3 == GREEN)
        green_count += 1;

    if (sc.color4 == GREEN)
        green_count += 1;

    return green_count;
}

static int count_color_YELLOW_secret_code(struct secret_code sc) {
    int yellow_count = 0;

    if (sc.color1 == YELLOW)
        yellow_count += 1;

    if (sc.color2 == YELLOW)
        yellow_count += 1;

    if (sc.color3 == YELLOW)
        yellow_count += 1;

    if (sc.color4 == YELLOW)
        yellow_count += 1;

    return yellow_count;
}

static int check_color_present(color_t c, int red_count, int blue_count, int green_count, int yellow_count) {
    int red_count_pc = 0;
    int blue_count_pc = 0;
    int green_count_pc = 0;
    int yellow_count_pc = 0;

    switch(c){
        case RED:
            if (red_count_pc != red_count)
                red_count_pc = red_count;
            return red_count_pc;
        case BLUE:
            if (blue_count_pc != blue_count)
                blue_count_pc = blue_count;
            return blue_count_pc;
        case GREEN:
            if (green_count_pc != green_count)
                green_count_pc += green_count;
            return green_count_pc;
        case YELLOW:
            if (yellow_count_pc != yellow_count)
                yellow_count_pc += yellow_count;
            return yellow_count_pc;
        default:
            break;
    };
    return -1;
}

static void color_count(color_t c, int *red_count, int *blue_count, int *green_count, int *yellow_count){
    switch(c){
        case RED:
            *red_count -=1;
            break;
        case BLUE:
            *blue_count -=1;
            break;
        case GREEN:
            *green_count -= 1;
            break;
        case YELLOW:
            *yellow_count -= 1;
            break;
        default:
            break;
    };
}

static int check_color_good(bool is_color1_good, bool is_color2_good, bool is_color3_good, bool is_color4_good) {
    int color_good = 0;

    if (is_color1_good)
        color_good += 1;

    if (is_color2_good)
        color_good += 1;

    if (is_color3_good)
        color_good += 1;

    if (is_color4_good)
        color_good += 1;

    return color_good;
}

int play_mastermind(struct secret_code sc, struct secret_code pc) {
    bool is_color1_good = false;
    bool is_color2_good = false;
    bool is_color3_good = false;
    bool is_color4_good = false;

    int red_count = count_color_RED_secret_code(sc);
    int blue_count = count_color_BLUE_secret_code(sc);
    int green_count = count_color_GREEN_secret_code(sc);
    int yellow_count = count_color_YELLOW_secret_code(sc);

    //Check color 1
    is_color1_good = pc.color1 == sc.color1;
    if (is_color1_good)
        color_count(pc.color1, &red_count, &blue_count, &green_count, &yellow_count);

    //Check color 2
    is_color2_good = pc.color2 == sc.color2;
    if (is_color2_good)
        color_count(pc.color2, &red_count, &blue_count, &green_count, &yellow_count);

    //Check color 3
    is_color3_good = pc.color3 == sc.color3;
    if (is_color3_good)
        color_count(pc.color3, &red_count, &blue_count, &green_count, &yellow_count);

    //Check color 4
    is_color4_good = pc.color4 == sc.color4;
    if (is_color4_good)
        color_count(pc.color4, &red_count, &blue_count, &green_count, &yellow_count);

    int color1_present = 0;
    int color2_present = 0;
    int color3_present = 0;
    int color4_present = 0;

    color1_present = check_color_present(pc.color1, red_count, blue_count, green_count, yellow_count);
    if (pc.color2 != pc.color1){
        color2_present = check_color_present(pc.color2, red_count, blue_count, green_count, yellow_count);
        //printf("Color 2: %d\n", pc.color2);
    }
    if (pc.color3 != pc.color1 && pc.color3 != pc.color2){
        color3_present = check_color_present(pc.color3, red_count, blue_count, green_count, yellow_count);
        //printf("Color 3: %d\n", pc.color3);
    }
    if (pc.color4 != pc.color1 && pc.color4 != pc.color2 && pc.color4 != pc.color3){
        color4_present = check_color_present(pc.color4, red_count, blue_count, green_count, yellow_count);
        //printf("Color 4: %d\n", pc.color4);
    }

    // Result
    int color_present = color1_present +
                        color2_present +
                        color3_present +
                        color4_present;

    int color_good = check_color_good(is_color1_good, is_color2_good, is_color3_good, is_color4_good);

    if (color_good == 4){
        printf("Congratulation ! You won !\n\n");
        return 1;
    }

    printf("\nPresent color: %d\n", color_present);
    printf("Well placed color : %d\n\n", color_good);
    return 0;
}
