#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    setName("compare answer for the problem xoaso");
    registerTestlibCmd(argc, argv);

    int ja = ans.readInt(1, (int)2e5, "ja");
    int pa = ouf.readInt(1, (int)2e5, "pa");
    ouf.readEoln();

    int n = inf.readInt(1, (int)2e5, "n");
    vector<int> arr(n);

    arr = inf.readInts(n, 1, (int)1e9, "a");

    if (ja != pa) quitf(_wa, "expected length %d, found length %d", ja, pa);

    vector<int> answer(ja);
    vector<int> input(ja);
    for (int i = 0; i < ja; ++i) {
        int index = ouf.readInt(1, (int)2e5, "i");
        input[i] = index;
        answer[i] = arr[index - 1];
    }

    for (int i = 1; i < ja; ++i) {
        if (answer[i - 1] + 1 != answer[i]) {
            quitf(_wa, "the answer is not valid, checking the %d-th element", i);
        }
        if (input[i - 1] >= input[i]) {
            quitf(_wa, "the answer is not valid, checking the %d-th element", i);
        }
    }

    quitf(_ok, "the answer is valid");
}
