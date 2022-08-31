cmake_minimum_required(VERSION 3.10)

# set the project name
project(Midnight C)

add_compile_definitions(DICE_STATE_TESTS)

add_executable(Midnight main.c utils/dice_state.c)