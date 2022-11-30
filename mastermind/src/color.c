#include "color.h"

struct secret_code;

struct secret_code secret_code_generator(void) {

    struct secret_code sc;

    srand(time(0));
    for (int i = 0; i <= 3; i++) {
        int n = rand() % 4;

        switch(i) {
            case 0:
                sc.color1 = n;
                break;
            case 1:
                sc.color2 = n;
                break;
            case 2:
                sc.color3 = n;
                break;
            case 3:
                sc.color4 = n;
                break;
            default:
                break;
        };
    }
    return sc;
}

void print_secret_code(struct secret_code sc) {
    printf("The secret code is:\n ");

    switch(sc.color1) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf(" - ");

    switch(sc.color2) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf(" - ");

    switch(sc.color3) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf(" - ");

    switch(sc.color4) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf("\n");
}

void print_player_code(struct secret_code sc) {
    printf("You chose the following code:\n ");

    switch(sc.color1) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf(" - ");

    switch(sc.color2) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf(" - ");

    switch(sc.color3) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf(" - ");

    switch(sc.color4) {
            case 0:
                printf("RED");
                break;
            case 1:
                printf("BLUE");
                break;
            case 2:
                printf("GREEN");
                break;
            case 3:
                printf("YELLOW");
                break;
            default:
                break;
    };
    
    printf("\n");
}
