
#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "board.h"
#include "position.h"
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    Snake *snake;
    Node *board[WIDTH][HEIGHT];
    int score;
} Game;

Game* new_game();
Game* game_init();
void game_tick(Game *game);
void render_board(Game *game);
void load_game(Game *game);

#endif
