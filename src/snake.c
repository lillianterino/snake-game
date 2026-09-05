#include "snake.h"

Snake* new_snake(){
    Snake *s = snake_init();
    set_snake(s, NULL, NULL, 0, 0);
    return s;
}

Snake* new_game_snake(){
    Snake *s = snake_init();
    set_snake(s, new_node(1,0), new_node(0,0), 2, 0);
    s->head->next = s->tail;
    s->tail->prev = s->head;
    return s;
}

Snake* snake_init(){
    Snake *s = malloc(sizeof(Snake));
    if(s == NULL){
        return NULL;
    }
    return s;
}

void set_snake(Snake *s, Node *head, Node *tail, int length, int direction){
    s->head = head;
    s->tail = tail;
    s->length = length;
    s->direction = direction;
}

void destroy_snake(Snake *s){
    if(s->head != NULL){
        destroy_node(s->head);
        destroy_node(s->tail);
        free(s);
    } else {
        free(s);
    }
    
}

void grow(Snake *s){
    Node *new = new_node(0,0);
    set_node(new, s->tail->pos, NULL, s->tail);
    s->tail->next = new;
    s->tail = new;
    s->length += 1;
}

void move(Snake *s){
    Node *start = s->head; // start of snake
    Position incr = start->pos; // value to pass on
    
    Position next_pos = *new_position(0,0); // new position
    set_coordinates(&next_pos, incr);
    move_position(&next_pos, s->direction);

    set_node_position(start, next_pos);
    shift(start->next, incr);
}

void shift(Node *n, Position incr){
    if(n != NULL){
        Position pass = n->pos;
        set_node_position(n, incr);
        shift(n->next, pass);
    }
}

void change_direction(Snake *s, int direction){
    if(s->direction != direction){
        if(s->direction == 0 || s->direction == 2){
            if(direction != 0 && direction != 2){
                s->direction = direction;
            }
        } else if (s->direction == 1 || s->direction == 3){
            if(direction != 1 && direction != 3){
                s->direction = direction;
            }
        }
    }
}

void print_snake(Snake *s){
    Node *curr = s->head;
    while(curr != NULL){
        print_node(curr);
        if(curr->next == NULL){
            printf("\n");
        } else {
            printf("-");
        }
        curr = curr->next;
    }
}


