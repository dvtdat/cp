// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 100010;
const ll MOD = 998244353;
const double eps = 1e-12;

ll a[maxN], f[maxN];

void solve()
{
    memset(a, 0LL, sizeof a);
    memset(f, 0LL, sizeof f);

    ll n; cin >> n;
    ll mx = 0;

    for (int i = 0; i < n; ++i)
    {
        ll u; cin >> u;
        a[u]++;
        mx = max(mx, u);
    }

    f[0] = 0;
    f[1] = a[1];

    for (int i = 0; i <= mx; ++i)
    {
        f[i] = max(f[i - 1], f[i - 2] + a[i] * i);
    }

    ll res = 0;
    for (int i = 0; i <= mx; ++i) res = max(res, f[i]);

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

