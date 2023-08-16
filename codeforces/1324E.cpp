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
    int n, H, L, R; cin >> n >> H >> L >> R;

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<int>> f(n + 5, vector<int>(n + 5, 0));

    auto check = [&](int L, int X, int R)
    {
        return (L <= X && X <= R);
    };

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= i + 1; ++j)
        {
            int tmp1, tmp2;

            tmp1 = f[i - 1][j - 1];
            if (check(L, (sum + a[i] - j + 1) % H, R)) tmp1++;

            tmp2 = f[i - 1][j];
            if (check(L, (sum + a[i] - j) % H, R)) tmp2++;

            // cout << sum + a[i] - j + 1 << '\n' << sum + a[i] - j << '\n';
            // cout << '\n';
            
            if (j) f[i][j] = max(tmp1, tmp2);
            else f[i][j] = tmp2;
        }
        sum += a[i];
    }

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 0; j <= n + 1; ++j) cout << f[i][j] << ' '; cout << '\n';
    // }

    int res = 0;
    for (int j = 0; j <= n; ++j)
    {
        res = max(res, f[n][j]);
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

