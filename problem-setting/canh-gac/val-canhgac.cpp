#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int test_case_count = inf.readInt(1, 1000, "t");
    inf.readEoln();

    int total_n = 0;
    int total_m = 0;

    for (int test_case = 1; test_case <= test_case_count; test_case++) {
        setTestCase(test_case);

        int n = inf.readInt(1, (int)2e5, "n");
        total_n += n;
        inf.readEoln();

        int m = inf.readInt(1, (int)2e5, "m");
        total_m += m;
        inf.readEoln();

        inf.readInts(n, 1, (int)1e9, "a");
        inf.readEoln();

        inf.readInts(m, 1, (int)1e9, "b");
        inf.readEoln();
    }

    ensuref(total_n <= 2e5, "sum of N exceeds 2e5");
    ensuref(total_m <= 2e5, "sum of M exceeds 2e5");

    inf.readEof();
}