#include <bits/stdc++.h>

using namespace std;

const string NAME = "prefix";
const int MINN = 1, MAXN = 10;
const int MINM = 1, MAXM = 5;

const int ntest = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int main()
{
    srand(time(NULL));
    for (int itest = 1; itest <= ntest; ++itest)
    {
        ofstream inp((NAME +".inp").c_str());

        int n = MINN + rand() % (MAXN - MINN + 1);
        int r = 1 + rand() % n;
        int l = 1 + rand() % n;

        if (l > r) swap(l, r);

        inp <<  n << ' ' << l << ' ' << r << '\n';

        for (int i = 1; i <= n; ++i)
        {
            inp << MINM + rand() % (MAXM - MINM + 1) << ' ';
        }

        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << itest << " WA\n";
            return 0;
        }

        cout << "Test " << itest << " AC\n";

        cout << "--------------------------------" << '\n';
    }
}
