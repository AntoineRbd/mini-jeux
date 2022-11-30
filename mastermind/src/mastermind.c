#include "mastermind.h"

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

