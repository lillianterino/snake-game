
#ifndef NODE_H
#define NODE_H

#include "position.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    Position pos;
} Node;


Node* new_node(int x, int y);
Node* node_init();
void destroy_node(Node *n);
void set_node(Node *n, Position p, Node *next, Node *prev);
void set_node_position(Node *n, Position p);
void print_node(Node *n);

#endif