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

void play_mastermind(struct secret_code sc, struct secret_code pc) {
    bool is_color1_good = false;
    bool is_color2_good = false;
    bool is_color3_good = false;
    bool is_color4_good = false;

    bool is_color1_present = false;
    bool is_color2_present = false;
    bool is_color3_present = false;
    bool is_color4_present = false;

    //Check color 1
    is_color1_present = pc.color1 == sc.color2 ||
                        pc.color1 == sc.color3 ||
                        pc.color1 == sc.color4;

    is_color1_good = pc.color1 == sc.color1;

    //Check color 2
    is_color2_present = pc.color2 == sc.color1 ||
                        pc.color2 == sc.color3 ||
                        pc.color2 == sc.color4;

    is_color2_good = pc.color2 == sc.color2;

    //Check color 3
    is_color3_present = pc.color3 == sc.color1 ||
                        pc.color3 == sc.color2 ||
                        pc.color3 == sc.color4;

    is_color3_good = pc.color3 == sc.color3;

    //Check color 4
    is_color4_present = pc.color4 == sc.color1 ||
                        pc.color4 == sc.color2 ||
                        pc.color4 == sc.color3;

    is_color4_good = pc.color4 == sc.color4;

    // Result
    int color_present = 0;
    int color_good = 0;
    
    if (is_color1_present){
        color_present += 1;
    }

    if (is_color2_present){
        color_present += 1;
    }

    if (is_color3_present){
        color_present += 1;
    }

    if (is_color4_present){
        color_present += 1;
    }


    if (is_color1_good) {
        color_good += 1;
    }

    if (is_color2_good) {
        color_good += 1;
    }

    if (is_color3_good) {
        color_good += 1;
    }

    if (is_color4_good) {
        color_good += 1;
    }

    if (color_good == 4){
        printf("Congratulation ! You won !\n\n");
        return;
    }

    printf("Present color: %d\n", color_present);
    printf("Well placed color : %d\n", color_good);
}
