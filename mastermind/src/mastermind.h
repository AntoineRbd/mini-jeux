#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <stddef.h>

#include "color.h"

int* input_code(int* lpBuffer, size_t nBufSize);
void play_mastermind(struct secret_code sc, struct secret_code pc);

#endif /* MASTERMIND_H */
