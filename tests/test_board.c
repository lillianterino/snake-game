#include "board.h"
#include "snake.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]){

    printf("Testing struct [ BOARD ]\n");

    Board *b = create_board();
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            assert(b->grid[i][j] == 0);
        }
    }

    print_board(b);
    printf("\n");

    Snake *s = create_snake();
    spawn_snake(b, s);
    print_board(b);
    print_node(s->head);
    assert(s->head->pos.x == 1);
    print_node(s->tail);
    printf("\n");

    set_coord(b, position_init(2,0), 1);
    print_board(b);
    printf("\n");

    Board *test = create_board();
    Snake *tester = create_snake();
    spawn_snake(test, tester);
    move_snake(test, tester);
    grow(tester);
    grow(tester);
    move_snake(test,tester);
    move_snake(test,tester);
    move_snake(test,tester);
    print_board(test);
    print_nodes(tester);


    printf("Test [ SUCCESS ]\n");

    return 0;

}