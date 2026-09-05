
#ifndef POSITION_H
#define POSITION_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Position;

Position* new_position(int x, int y);
Position* position_init();
void set_coordinates(Position *p, Position n);
void set_values(Position *p, int x, int y);
void print_position(Position p);
void move_position(Position *p, int d);
void x_incr(Position *p);
void y_incr(Position *p);
void x_decr(Position *p);
void y_decr(Position *p);
bool equals(Position p, Position q);

#endif