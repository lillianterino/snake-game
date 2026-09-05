#include "game.h"

Game* new_game();
Game* game_init();
void game_tick(Game *game);
void render_board(Game *game);
void load_board(Game *game);
bool grid_to_pos(Position *p, int i, int j);
int get_direction(Snake *s, Node *n);
void loop(Game *game, int n);
bool out_of_bounds(Position p);
bool check_bounds(Game *game);

int main(int argc, char *argv[]){

    Game *game = new_game();
    load_board(game);
    render_board(game);
    
    loop(game, 4);
    change_direction(game->snake, 3);
    loop(game, 2);
    grow(game->snake);
    change_direction(game->snake, 2);
    loop(game, 4);
    change_direction(game->snake, 1);
    loop(game, 2);
    change_direction(game->snake, 0);
    loop(game, 5);
    change_direction(game->snake, 1);
    loop(game,2);
    
    return 0;
}

Game* new_game(){
    Game *game = game_init();
    game->snake = new_game_snake();
    game->score = 0;
}

Game* game_init(){
    Game *game = malloc(sizeof(Game));
    if(game == NULL){
        return NULL;
    }
    return game;
}

void loop(Game *game, int n){
    for(int i = 0; i < n; i++){
        game_tick(game);
    }
}

void game_tick(Game *game){
    Position tail_index = game->snake->tail->pos;
    move(game->snake);
    game->board[tail_index.y][tail_index.x] = NULL;
    load_board(game);
    render_board(game);
    usleep(200000);
}

bool check_bounds(Game *game){
    if(out_of_bounds(game->snake->head->pos)){
        return false;
    } else if(equals(game->snake->head->pos, game->snake->tail->pos)){
        return false;
    } else {
        return true;
    }
}

bool out_of_bounds(Position p){
    if(p.x >= WIDTH || p.x < 0){
        return true;
    } else if (p.y >= HEIGHT || p.y < 0){
        return true;
    } else {
        return false;
    }
}

void render_board(Game *game){
    for(int i = 0; i < WIDTH; i++){
        printf("| ");
        for(int j = 0; j < HEIGHT; j++){
            if(game->board[i][j] != NULL){
                int d = get_direction(game->snake, game->board[i][j]);
                if(d == 0){
                    printf("---");
                } else if (d == 1){
                    printf(" | ");
                }
            } else {
                printf(".  ");
            }
        }
        printf("|\n");
    }
}

void load_board(Game *game){
    Node *curr = game->snake->head;
    while(curr != NULL){
        set_position(game->board, curr->pos, curr);
        curr = curr->next;
    }
    //set_position(game->board, curr->pos, NULL);
}

bool grid_to_pos(Position *p, int i, int j){
    if(i == p->y && j == p->x){
        return true;
    } else {
        return false;
    }
}

int get_direction(Snake *s, Node *n){
    if(n->prev != NULL){
        Node *m = n->prev;
        int x = n->pos.x - m->pos.x;
        int y = n->pos.y - m->pos.y;
        if(x != 0){
            return 0;
        } else if (y != 0){
            return 1;
        } else {
            return -1;
        }
    } else {
        if(s->direction == 0 || s->direction == 2){
            return 0;
        } else {
            return 1;
        }
    }
    
    return 0;
}

