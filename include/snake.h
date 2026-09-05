
#ifndef SNAKE_H
#define SNAKE_H

#include "node.h"
#include <stdbool.h>

typedef struct {
    Node *head;
    Node *tail;
    int length;
    int direction;
} Snake;

Snake* new_snake();
Snake* new_game_snake();
Snake* snake_init();
void set_snake(Snake *s, Node *head, Node *tail, int length, int direction);
void grow(Snake *s);
void move(Snake *s);
void shift(Node *n, Position incr);
void change_direction(Snake *s, int direction);
void print_snake(Snake *s);
void destroy_snake(Snake *s);

#endif