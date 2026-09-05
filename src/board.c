#include "board.h"

void set_position(Node *board[WIDTH][HEIGHT], Position p, Node *n){
    if(n != NULL){
        board[p.y][p.x] = n;
    } else {
        board[p.y][p.x] = NULL;
    }
}
