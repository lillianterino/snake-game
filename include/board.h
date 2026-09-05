
#ifndef BOARD_H
#define BOARD_H

#define WIDTH 10
#define HEIGHT 10

#include "position.h"

typedef struct {
    int grid[WIDTH][HEIGHT];
} Board;

Board* new_board();
Board* new_game_board();
Board* board_init();
void set_position(Board *b, Position p, int state);
void print_board(Board *b);
void clear_board(Board *b);

#endif