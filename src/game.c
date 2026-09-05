#include "game.h"

Game* new_game();
Game* game_init();
void game_tick(Game *game);
void render_board(Game *game);
void load_board(Game *game);
bool grid_to_pos(Position *p, int i, int j);

int main(int argc, char *argv[]){

    Game *game = new_game();
    load_board(game);
    grow(game->snake);
    sleep(1);
    for(int i = 0; i < 4; i++){
        game_tick(game);
        sleep(1);
    }
    change_direction(game->snake, 3);
    for(int i = 0; i < 4; i++){
        game_tick(game);
        sleep(1);
    }
    change_direction(game->snake, 2);
    for(int i = 0; i < 4; i++){
        game_tick(game);
        sleep(1);
    }
    change_direction(game->snake, 1);
    for(int i = 0; i < 4; i++){
        game_tick(game);
        sleep(1);
    }
    
    print_snake(game->snake); 

    return 0;
}

Game* new_game(){
    Game *game = game_init();
    game->snake = new_game_snake();
    game->board = new_game_board();
    game->score = 0;
}

Game* game_init(){
    Game *game = malloc(sizeof(Game));
    if(game == NULL){
        return NULL;
    }
    return game;
}

void game_tick(Game *game){
    move(game->snake);
    load_board(game);
    render_board(game);
}

void render_board(Game *game){
    for(int i = 0; i < WIDTH; i++){
        printf("|");
        for(int j = 0; j < HEIGHT; j++){
            if(game->board->grid[i][j] == 1){
                if(grid_to_pos(&game->snake->head->pos, i, j)){
                    printf(":>-");
                } else if (grid_to_pos(&game->snake->tail->pos, i, j)){
                    printf("<-o");
                } else {
                    printf("-o-");
                }
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }
}

void load_board(Game *game){
    clear_board(game->board);
    Node *curr = game->snake->head;
    while(curr != NULL){
        set_position(game->board, curr->pos, 1);
        curr = curr->next;
    }
}

bool grid_to_pos(Position *p, int i, int j){
    if(i == p->y && j == p->x){
        return true;
    } else {
        return false;
    }
}

