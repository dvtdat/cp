// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 1e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    vector<vector<ll>> f(n + 1, vector<ll>(3, infLL));

    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

    f[1][0] = 0;
    f[1][1] = b[1];
    f[1][2] = b[1] * 2;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (a[i] + j != a[i - 1] + k) f[i][j] = min(f[i][j], f[i - 1][k] + b[i] * j);
            }
        }
    }

    ll res = infLL;
    for (int i = 0; i < 3; ++i) res = min(res, f[n][i]);

    cout << res << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
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

