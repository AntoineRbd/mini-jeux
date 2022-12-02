#include "color.h"
#include "mastermind.h"

#include <stdio.h>
#include <stdbool.h>
 
int main()
{
    
    struct secret_code sc = secret_code_generator();
    //print_secret_code(sc);

    printf(" --- Start game ! --- \n");


    struct secret_code player_code;
    int code[4];

    while (1) {
     
        printf("Chose your code:\n- RED = 0\n- BLUE = 1\n- GREEN = 2\n- YELLOW = 3\n");

        input_code(code, sizeof(code));

        //printf("Your code : %s\n", code);

        for(int i = 0; i < 4; i++){
            switch(i){
                case 0:
                    player_code.color1 = code[i];
                    break;
                case 1:
                    player_code.color2 = code[i];
                    break;
                case 2:
                    player_code.color3 = code[i];
                    break;
                case 3:
                    player_code.color4 = code[i];
                    break;
                default:
                    break;
            };
        }

        bool color_valid = check_color_valid(player_code);
        if (!color_valid) {
            printf("Color are not valid, retry...\n");
        }
        else {
            print_player_code(player_code);

            play_mastermind(sc, player_code);
        }
    }
 
    return 0;
}
