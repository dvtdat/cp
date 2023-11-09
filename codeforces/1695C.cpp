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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> fMax(n + 1, vector<int>(m + 1, -inf));
    vector<vector<int>> fMin(n + 1, vector<int>(m + 1, inf));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }

    if ((n + m) % 2 == 0)
    {
        cout << "NO\n"; return;
    }

    fMax[1][1] = a[1][1];
    fMin[1][1] = a[1][1];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1) continue;
            fMax[i][j] = a[i][j] + max(fMax[i - 1][j], fMax[i][j - 1]);
            fMin[i][j] = a[i][j] + min(fMin[i - 1][j], fMin[i][j - 1]);
        }
    }

    if (fMax[n][m] < 0 || fMin[n][m] > 0) cout << "NO\n";
    else cout << "YES\n";
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

