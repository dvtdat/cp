// xuan mang tinh yeu muon nha

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

int a[maxN];

void solve()
{
    int n, l, r, x; cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

    int res = 0;

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int sum = 0, mn = inf, mx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!(mask & (1 << i))) continue;
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            sum += a[i];
        }   

        //cout << sum << '\n';

        res += (l <= sum && sum <= r && mx - mn >= x);
    }

    cout << res;
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

