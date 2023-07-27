/*
    Description: This is the test generating code together with the checker. The user should have
    2 separate solution for a problem, with one that will be submitted and one that guaranteed to
    work well under low constraint. They should be compile into <name>.exe and <name>_trau.exe
    (which is suggested to be compiled with termimal).
*/

#include <bits/stdc++.h>

using namespace std;

const string NAME = "template";
const int NTEST = 100;

// EXAMPLE OF SETTING CONSTRAINT
const int MINN = 1, MAXN = 10;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int main()
{
    srand(time(NULL));
    for (int ITEST = 1; ITEST <= NTEST; ++ITEST)
    {
        ofstream inp((NAME + ".inp").c_str());

        // EXAMPLE OF GENERATING RANDOM NUMBER
        int N = MINN + rand() % (MAXN - MINN + 1);
        cout << N << '\n';

        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << ITEST << " WRONG ANSWER\n";
            return 0;
        }
        cout << "Test " << ITEST << " ACCEPTED!\n";
        cout << "--------------------------------" << '\n';
    }
}
