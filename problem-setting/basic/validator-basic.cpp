#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, (int)2e5, "n");
    inf.readEoln();

    inf.readInts(n, 1, (int)1e9, "a");
    inf.readEoln();
    
    inf.readEof();
}