// cruel

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

int p[maxN][35];

void process()
{
    for (int i = 0; i <= 200000; ++i)
    {
        for (int j = 0; j <= 30; ++j)
        {
            p[i][j] = ((i & (1 << j)) ? 1 : 0);
            if (i != 0) p[i][j] += p[i - 1][j];
        }
    }
}

void solve()
{
    int l, r; cin >> l >> r;
    int mx = 0;

    for (int i = 0; i <= 30; ++i)
    {
        mx = max(mx, p[r][i] - p[l - 1][i]);
    }

    cout << r - l + 1 - mx << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    
    int test; cin >> test;
    process();
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

