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
const int maxN = 2010;
const ll MOD = 1000000007;
const double eps = 1e-12;

int f[maxN][maxN];
bool can[maxN][maxN];

void solve()
{
    memset(f, 0, sizeof f);
    memset(can, 1, sizeof can);

    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char c; cin >> c;
            can[i][j] = 1;
            if (c == '#')
            {
                can[i][j] = 0; f[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; ++i) 
    {
        if (!can[1][i]) break;
        f[1][i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!can[i][1]) break;
        f[i][1] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            if (can[i][j]) f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;
        }
    }

    cout << f[n][m] % MOD;
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

