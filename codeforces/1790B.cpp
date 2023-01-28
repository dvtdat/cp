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

void solve()
{
    int n, s, r; cin >> n >> s >> r;

    int mx = s - r;

    cout << mx << ' ';
    
    for (int k = 1; k <= n - 1; ++k)
    {
        for (int f = 1; f <= mx; ++f)
        {
            for (int j = 1; j <= mx; ++j)
            {
                if (f * k + (n - 1 - k) * j == r)
                {
                    for (int i = 0; i < k; ++i) cout << f << ' ';
                    for (int i = 0; i < n - 1 - k; ++i) cout << j << ' ';
                    cout << '\n';
                    return;
                }
            }
        }
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

