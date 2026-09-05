#include "board.h"

Board* new_board(){
    Board *b = board_init();
    return b;
}

Board* new_game_board(){
    Board *b = board_init();
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            b->grid[i][j] = 0;
        }
    }
    return b;
}

Board* board_init(){
    Board *b = malloc(sizeof(Board));
    if(b == NULL){
        return NULL;
    }
    return b;
}

void set_position(Board *b, Position p, int state){
    if(state == 1 || state == 0){
        b->grid[p.y][p.x] = state;
    }
}

void print_board(Board *b){
    for(int i = 0; i < WIDTH; i++){
        printf("| ");
        for(int j = 0; j < HEIGHT; j++){
            printf("%d ", b->grid[i][j]);
        }
        printf("|\n");
    }
}

void clear_board(Board *b){
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            b->grid[i][j] = 0;
        }
    }
}

// void spawn_snake(Board *b, Snake *s){
//     b->grid[0][0] = 1;
//     b->grid[0][1] = 1;
//     s->head->pos = *position_init(1,0);
//     s->tail->pos = *create_position();
// }

// void move_snake(Board *b, Snake *s){
//     Position end = s->tail->pos;
//     move(s);
//     Node* curr = s->head;
//     while(curr != NULL){
//         set_coord(b, &curr->pos, 1);
//         curr = curr->next;
//     }
//     set_coord(b, &end, 0);
// }

