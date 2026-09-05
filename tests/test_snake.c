#include "snake.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]){

    printf("Testing struct [ SNAKE ]\n");

    Snake *s = create_snake();
    assert(s->head != NULL);
    assert(s->tail != NULL);
    assert(s->length == 2);
    assert(s->direction == 0);

    print_snake(s);
    printf("\n");

    grow(s);
    grow(s);
    grow(s);
    assert(s->length == 5);
    print_snake(s);
    printf("\n");

    change_direction(s, 1);
    assert(s->direction == 1);
    change_direction(s, 3);
    assert(s->direction == 1);
    change_direction(s, 0);

    printf("\n");
    print_nodes(s);

    Snake *t = create_snake();
    for(int i = 0; i < 5; i++){
        grow(t);
    }
    print_nodes(s);
    printf("\n");
    for(int i = 0; i < 5; i++){
        move(s);
        print_nodes(s);
    }

    destroy_snake(s);

    printf("Test [ SUCCESS ]\n");

    return 0;

}