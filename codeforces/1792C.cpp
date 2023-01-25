// NOT DONE PLS NO

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

int a[maxN], ok[maxN];

void solve()
{
    memset(a, 0, sizeof a);
    memset(ok, 0, sizeof ok);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int res = (n + 1) / 2;

    for (int i = 0; i < n; ++i)
    {
        ok[a[i]] = ok[a[i] - 1] + (a[i] != 1 && a[i] != n);
        // cout << ok[a[i]] << ' ';
    }

    for (int i = 1; i <= n; ++i)
    {

        cout << ok[i] << ' ';
        res = min(res, n - ok[i] - 1);
    }

    cout << res << '\n';
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

