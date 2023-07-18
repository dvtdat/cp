// NOT DONE YET

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
const ll MOD = 1000000009;
const double eps = 1e-12;

int a[110];
int f[110][400010];

void solve()
{
    memset(f, 0, sizeof f);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 0; i <= n; ++i) f[i][0] = 1;
    for (int i = 1; i <= m; ++i) f[1][i] = (max(0, a[i] - i + 1) + f[1][i - 1]) % MOD;


    for (int i = 1; i <= m; ++i)
    {
        for (int j = 2; j <= n; ++j)
        {
            f[j][i] = f[j][i] + f[j][i - 1] + (f[j - 1][min(i, a[j])] - f[j - 1][max(0, i - a[j] - 1)]);
            f[j][i] %= MOD;
        }
    }

    cout << (f[n][m] - f[n][m - 1]) % MOD;
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

