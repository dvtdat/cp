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
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (a[1] == 0)
    {
        for (int i = 1; i <= m; ++i) f[1][i] = 1;
    }
    else f[1][a[1]] = 1;

    auto calc = [&](int i, int j)
    {
        (f[i][j] += f[i - 1][j]) %= MOD;
        (f[i][j] += (j - 1 > 0 ? f[i - 1][j - 1] : 0)) %= MOD;
        (f[i][j] += (j + 1 <= m ? f[i - 1][j + 1] : 0)) %= MOD;
    };

    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; ++j)
            {
                calc(i, j);
            }
        }
        else
        {
            calc(i, a[i]);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= m; ++i) (res += f[n][i]) %= MOD;

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

