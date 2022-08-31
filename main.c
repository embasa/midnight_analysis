#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utils/dice_state.h"

int main(int argc, char *argv[]) {
    srand(time(0)*getpid());
    printf("Midnight dice game: also known as 1-4-24\n");
#ifdef DICE_STATE_TESTS
    runDiceStateTests();
#endif

    return 0;
}
