#include "node.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]){

    printf("Testing struct [ NODE ]\n");

    Node *n = create_node();
    assert(n->next == NULL);
    assert(n->prev == NULL);
    assert(n->pos.x == 0);
    assert(n->pos.y == 0);

    update_position(n, 1, 2);
    assert(n->pos.x == 1);
    assert(n->pos.y == 2);

    print_node(n);
    printf("\n");

    destroy_node(n);

    printf("Test [ SUCCESS ]\n");

    return 0;

}