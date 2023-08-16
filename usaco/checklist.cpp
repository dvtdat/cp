// 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 1e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

ll calc(ii x, ii y)
{
    x.first -= y.first;
    x.second -= y.second;
    return (x.first * x.first) + (x.second * x.second);
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<ii> h(n + 1), g(m + 1);
    for (int i = 1; i <= n; ++i) cin >> h[i].first >> h[i].second;
    for (int i = 1; i <= m; ++i) cin >> g[i].first >> g[i].second;

    vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2, infLL)));

    f[1][0][0] = 0;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i > 1) f[i][j][0] = min(f[i][j][0], f[i - 1][j][0] + calc(h[i], h[i - 1]));
            if (j > 1) f[i][j][1] = min(f[i][j][1], f[i][j - 1][1] + calc(g[j], g[j - 1]));

            if (i <= 0 || j <= 0) continue;

            f[i][j][0] = min(f[i][j][0], f[i - 1][j][1] + calc(h[i], g[j]));
            f[i][j][1] = min(f[i][j][1], f[i][j - 1][0] + calc(h[i], g[j]));
        }
    }

    cout << f[n][m][0] << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("checklist");
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

