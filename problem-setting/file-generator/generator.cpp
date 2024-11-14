#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int test = opt<int>("test", 1);

    int minN = opt<int>("min-n", 1);
    int maxN = opt<int>("max-n", 100);
    // ...

    for (int t = 1; t <= test; ++t) {
        ofstream inp(format("tests/%02d.in", t).c_str());
        
        int n = rnd.next(minN, maxN);
        // ...

        inp << n << '\n';
        // ...

        inp.close();

        ofstream out(format("tests/%02d.ans", t).c_str());
        char command[100];
        sprintf(command, "./main.exe < tests/%02d.in > tests/%02d.ans", t, t);
        system(command);
        out.close();
    }
}