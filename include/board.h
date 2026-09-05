
#ifndef BOARD_H
#define BOARD_H

#define WIDTH 10
#define HEIGHT 10

#include "position.h"
#include "node.h"

void set_position(Node *board[WIDTH][HEIGHT], Position p, Node *n);

#endif