#include "node.h"

Node* new_node(int x, int y){
    Node *n = node_init();
    set_node(n, *new_position(x,y), NULL, NULL);
    return n;
}

Node* node_init(){
    Node *n = malloc(sizeof(Node));
    if(n == NULL){
        return NULL;
    }
    return n;
}

void set_node(Node *n, Position p, Node *next, Node *prev){
    n->next = next;
    n->prev = prev;
    n->pos = p;
}

void destroy_node(Node *n){
    free(n);
}

void set_node_position(Node *n, Position p){
    n->pos = p;
}

void print_node(Node *n){
    print_position(n->pos);
}
