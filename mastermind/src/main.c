#include "color.h"
 
int main()
{
    
    struct secret_code sc = secret_code_generator();
    //print_secret_code(sc);

    printf(" --- Start game ! --- \n");

    while (1) {
        int code;
     
        printf("Chose your code:\n- RED = 0\n- BLUE = 1\n- GREEN = 2\n- YELLOW = 3\n");

        code = getc(stdin);
    }
 
    return 0;
}
