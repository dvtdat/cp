#include "a.h"
#include "b.h"
#include <stdio.h>

int main() {
    struct A* objectA = makeA(1, 2);
    struct B* objectB = makeB(3, 4, "objectB");

    int res = calculate(objectA, (struct A*) objectB);

    printf("Result: %d\n", res);
}