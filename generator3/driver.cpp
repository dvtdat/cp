#include <bits/stdc++.h>

const int MINN = 1, MAXN = 100000;
const int MINM = 1, MAXM = 1000000;
const int ntest = 1;

using namespace std;

int main()
{
    srand(time(NULL));

    for (int itest = 1; itest <= ntest; ++itest)
    {
        ofstream inp("prefix.inp");

        int n = MINN + rand() % (MAXN - MINN + 1);
        int l = 1 + rand() % n;
        int r = 1 + rand() % n;

        if (l > r) swap(l, r);

        inp << n << ' ' << l << ' ' << r << '\n';

        for (int i = 0; i < n; ++i)
        {
            inp << MINM + rand() % (MAXM - MINM + 1) << ' ';
        }

        inp.close();

        system("prefix.exe");
        system("prefix_trau.exe");

        if (system("fc prefix.out prefix.ans") != 0)
        {
            cout << "Test " << itest << " WA\n";
            return 0;
        }

        cout << "Test " << itest << " AC\n";
        cout << "------------------------\n";
    }

}
