// 

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

char c[20][20];

void solve()
{
    memset(c, ' ', sizeof c);

    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cin >> c[i][j];
        }
    }

    int x, y; cin >> x >> y;

    x = x % 3; y = y % 3;
    if (!x) x = 3;
    if (!y) y = 3;

    int cnt = 0;
    for (int i = 3 * (x - 1) + 1; i <= 3 * x ; ++i)
    {
        for (int j = 3 * (y - 1) + 1; j <= 3 * y; ++j)
        {
            if (c[i][j] == '.') cnt++, c[i][j] = '!';
        }
    }

    if (!cnt)
    {
        for (int i = 1; i < 15; ++i)
        {
            for (int j = 1; j < 15; ++j)
            {
                if (c[i][j] == '.') c[i][j] = '!';
            }
        }
    }

    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cout << c[i][j];
            if (j % 3 == 0) cout << ' ';
        }
        cout << '\n';
        if (i % 3 == 0) cout << '\n';
    }

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

