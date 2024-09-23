#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int minValue = opt<int>("min-value", 1);
    int maxValue = opt<int>("max-value", (int)1e9);

    int a = rnd.next(minValue, maxValue);
    int b = rnd.next(minValue, maxValue);
    int c = rnd.next(minValue, maxValue);

    println(a);
    println(b);
    println(c);
}