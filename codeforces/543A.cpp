// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
// const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n, m, b; cin >> n >> m >> b;
    ll MOD; cin >> MOD;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<ll>> f(m + 1, vector<ll>(b + 1, 0LL));

    // BASE CASE
    f[0][0] = 1LL;
    
    // PULL DP
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int k = 0; k <= b; ++k)
            {
                if (j - 1 < 0 || k - a[i] < 0) continue;
                (f[j][k] += f[j - 1][k - a[i]]) %= MOD;
            }
        }
    }

    // for (int j = 0; j <= m; ++j)
    // {
    //     for (int k = 0; k <= b; ++k) cout << f[j][k] << ' '; cout << '\n';
    // }
    // cout << '\n';

    ll res = 0LL;
    for (int i = 0; i <= b; ++i) (res += f[m][i]) %= MOD;

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

