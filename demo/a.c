#include "a.h"
#include <stdlib.h>

struct A {
    int x;
    int y;
};

struct A* makeA(int x, int y) {
    struct A* a = malloc(sizeof(struct A));
    a->x = x;
    a->y = y;
    return a;
}

int calculate(struct A* a, struct A* aa) {
    return a->x + a->y + aa->x + aa->y;
}