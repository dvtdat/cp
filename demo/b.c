#include "b.h"
#include <stdlib.h>

struct B {
    int x;
    int y;
    char* name;
};

struct B* makeB(int x, int y, char* name) {
    struct B* b = malloc(sizeof(struct B));
    b->x = x;
    b->y = y;
    b->name = name;
    return b;
}

int calculateB(struct B* b, struct B* bb) {
    return b->x + b->y + bb->x + bb->y;
}