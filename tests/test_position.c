
#include "position.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]){

    printf("Testing struct [ POSITION ]\n");

    Position *p = create_position();
    assert(p->x == 0);
    assert(p->y == 0);
    char output[50];
    printf("%s\n", position_as_string(p, output, sizeof(output)));

    update_coords(p, 1,1);
    assert(p->x == 1);
    assert(p->y == 1);
    printf("%s\n", position_as_string(p,output, sizeof(output)));

    update_coords(p, 3, 5);
    assert(p->x == 3);
    assert(p->y == 5);
    printf("%s\n", position_as_string(p,output, sizeof(output)));

    printf("Test [ SUCCESS ]\n");

    return 0;

}