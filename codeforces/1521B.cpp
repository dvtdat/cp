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
const int inf = 1e9 + 7;
const int maxN = 2000010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;
    int mn = inf, x, y, index = 0;


    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        
        if (u < mn)
        {
            mn = u; index = i;
        }
    }

    x = mn; y = mn + 1;

    if (n == 1)
    {
        cout << 0 << '\n'; return;
    }
    cout << n << '\n';
    if (index != 0) cout << 1 << ' ' << index + 1 << ' ' << x << ' ' << y << '\n';
    else cout << 1 << ' ' << 2 << ' ' << x << ' ' << y << '\n';

    for (int i = 1; i < n; ++i)
    {
        cout << 1 << ' ' << i + 1 << ' ' << x << ' ' << (i & 1 ? y : x) << '\n';
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
    int test; cin >> test;
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

