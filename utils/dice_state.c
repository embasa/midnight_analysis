#include <stdio.h>
#include <stdlib.h>
#include "dice_state.h"

#define MIN_VALUE 1
#define MAX_VALUE 6

typedef struct dice_state {
    int selected[MAX_VALUE];
    int num_selected;
    int remaining[MAX_VALUE];
    int num_remaining;
    int current_score;
} dice_state;

bool hasDiceByValue(dice_state_ptr dice, int value) {
    if (NULL == dice) return false;
    if ((value < MIN_VALUE) || (MAX_VALUE < value)) return false;
    return dice->remaining[value-1] > 0;
}

int selectDiceByValue(dice_state_ptr dice, int value) {
    if (NULL == dice) return -1;
    if ((value < MIN_VALUE) || (MAX_VALUE < value)) return -1;
    if (dice->remaining[value-1] <= 0) return -1;


    // if this is our first 1 or 4, we do not included in score
    if ((dice->selected[value-1] > 0) || (value != 1 && (value != 4))) {
        dice->current_score+=value;
    }

    dice->selected[value-1]++;
    dice->num_selected++;

    dice->remaining[value-1]--;
    dice->num_remaining--;

    return 0;
}

bool hasOneDice(dice_state_ptr dice) {
    if (NULL == dice) return false;
    if (MAX_VALUE < 1) return false;
    return dice->remaining[1-1] > 0;
}

bool hasFourDice(dice_state_ptr dice) {
    if (NULL == dice) return false;
    if (MAX_VALUE < 4) return false;
    return dice->remaining[4-1] > 0;
}

int rollDice(dice_state_ptr dice) {
    int i = 0;
    if (NULL == dice) return 0;
    while (i < dice->num_remaining) {
        dice->remaining[rand()%MAX_VALUE]++;
        i++;
    }
    return 0;
}

int diceRemaining(dice_state_ptr dice) {
    if (NULL == dice) return 0;
    return dice->num_remaining;
}

int printDiceState(dice_state_ptr dice) {
     if (NULL == dice) {
        return 0;
    }
    if (dice->num_selected == 0) {
        printf("Selected  dice: None\n");
    } else {
        printf("Selected  dice:\n");
        int value = 0;
        while (value < MAX_VALUE) {
            int count = 0;
            while (count < dice->selected[value]) {
                printf("%d ", value+1);
            }
        }
        printf("\n");
    }

    if (dice->num_remaining == 0) {
        printf("Remaining dice: None\n");
    } else {
        printf("Remaining dice:\n");
        int value = 0;
        while (value < MAX_VALUE) {
            int count = 0;
            while (count < dice->remaining[value]) {
                printf("%d ", value+1);
            }
        }
        printf("\n");
    }

    printf("current score = %d\n", dice->current_score);
    return 0;
}


#ifdef DICE_STATE_TESTS
int runDiceStateTests() {
    printf("Run tests for dice_state.h interface here.\n");
    return 0;
}
#endif
