#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int minN = opt<int>("min-n", 1);
    int maxN = opt<int>("max-n");

    int minValue = opt<int>("min-value", 1);
    int maxValue = opt<int>("max-value", (int)1e9);

    int n = rnd.next(minN, maxN);

    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        array[i] = rnd.next(minValue, maxValue);
    }

    println(n);
    println(array);
}