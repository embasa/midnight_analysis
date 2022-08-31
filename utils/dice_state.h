#ifndef __BE_DICE_STATE__
#define __BE_DICE_STATE__
#include <stdbool.h>

typedef struct dice_state* dice_state_ptr;

bool hasDiceByValue(dice_state_ptr dice, int value);

/**
 * @brief selects a 'dice' with the value specified in
 * the parameter if it exists.
 * 
 * @param dice A handle to the dice state.
 * @param value A handle to a dice value being select.
 * @return int Returns 0 if dice selected, else 1.
 */
int selectDiceByValue(dice_state_ptr dice, int value);
/**
 * @brief Returns true if at least one of the selccted
 * dice contains a 1.
 * 
 * @param dice A handle to the dice state.
 * @return true 
 * @return false 
 */
bool hasOneDice(dice_state_ptr dice);
/**
 * @brief Returns true if at least one of the selected
 * dice contain's a 4.
 * 
 * @param dice A handle to the dice state.
 * @return true 
 * @return false 
 */
bool hasFourDice(dice_state_ptr dice);

/**
 * @brief Rolls all the remaining dice.
 * 
 * @param dice A handle to the dice state.
 * @return int Return 0 if successful, else 1.
 */
int rollDice(dice_state_ptr dice);

/**
 * @brief Returns the number of dice remaining.
 * 
 * @param dice A handle to the dice state.
 * @return int The number of dice remaining.
 */
int diceRemaining(dice_state_ptr dice);

/**
 * @brief Prints all the information about
 * the state of the dice.
 * 
 * @param dice A handle to the dice state.
 * @return int Return 0 if valid state, else 1.
 */
int printDiceState(dice_state_ptr dice);

#ifdef DICE_STATE_DEBUG
int runDiceStateTests();
#endif

#endif /* __BE_DICE_STATE__ */