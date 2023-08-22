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
    string s; cin >> s;
    s = '.' + s;

    string t = ".hard";
    vector<int> a(n + 1);
    vector<vector<ll>> f(5, vector<ll>(n + 1, infLL));

    for (int i = 1; i <= n; ++i) cin >> a[i];

    f[1][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[1][i] = f[1][i - 1];
        if (s[i] == t[1]) f[1][i] += a[i];
    }

    for (int k = 2; k <= 4; ++k)
    {
        if (s[1] == t[k]) f[k][1] = a[1];
        f[k][1] = 0;

        for (int i = 2; i <= n; ++i)
        {
            if (s[i] != t[k])
            {
                f[k][i] = f[k][i - 1];
                continue;
            }

            f[k][i] = min(f[k][i - 1] + a[i], f[k - 1][i - 1]);
        }
    }

    ll res = infLL;
    for (int k = 1; k <= 4; ++k)
    {
        res = min(res, f[k][n]);
    }

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

