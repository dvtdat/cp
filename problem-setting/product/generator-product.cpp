#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int minN = opt<int>("min-n", 1);
    int maxN = opt<int>("max-n", (int)2e5);

    int minVal = opt<int>("min-val", 1);
    int maxVal = opt<int>("max-val", (int)1e9);

    int n = rnd.next(minN, maxN);
    vector<int> array(n);

    for (int i = 0; i < n; ++i) {
        array[i] = rnd.next(minVal, maxVal);
    }

    println(n);
    println(array);
}