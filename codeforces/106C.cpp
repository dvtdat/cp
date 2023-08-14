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
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;

    vector<int> a(m + 1), b(m + 1), c(m + 1), d(m + 1);
    vector<vector<int>> f(n + 5, vector<int>(m + 5, 0));

    for (int i = 1; i <= m; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i = 0; i < n; ++i) f[i][0] = 0; // BASE CASE

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // k is the amount of bun that can be made BASED on the amount of jth stuffing availabe
            for (int k = 0; k <= a[j] / b[j]; ++k) 
            {
                if (i - c[j] * k < 0) break;
                f[i][j] = max(f[i][j], f[i - c[j] * k][j - 1] + d[j] * k);
            }
        }
    }

    int res = 0;

    for (int i = 0; i <= n; ++i)
    {
        res = max(res, f[i][m] + (n - i) / c0 * d0);
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

