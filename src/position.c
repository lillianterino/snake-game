#include "position.h"

Position* new_position(int x, int y){
    Position *p = position_init();
    set_values(p, x, y);
    return p;
}

Position* position_init(){
    Position *p = malloc(sizeof(Position));
    if(p == NULL){
        return NULL;
    }
    return p;
}

void set_coordinates(Position *p, Position n) {
    p->x = n.x;
    p->y = n.y;
}

void set_values(Position *p, int x, int y){
    p->x = x;
    p->y = y;
}

void print_position(Position p){
    printf("(%d,%d)", p.x, p.y);
}

void move_position(Position *p, int d){
    if(d == 0){
        x_incr(p);
    } else if (d == 1){
        y_incr(p);
    } else if (d == 2){
        x_decr(p);
    } else if (d == 3){
        y_decr(p);
    }
}

void x_incr(Position *p){
    p->x += 1;
}

void y_incr(Position *p){
    p->y -= 1;
}

void x_decr(Position *p){
    p->x -= 1;
}

void y_decr(Position *p){
    p->y += 1;
}

bool equals(Position p, Position q){
    if(p.x == q.x){
        if(p.y == q.y){
            return true;
        }
    }
    return false;
}

