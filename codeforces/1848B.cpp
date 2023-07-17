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
    int n, k; cin >> n >> k;
    vector<vector<int>> a(k + 1);

    for (int i = 1; i <= k; ++i) a[i].push_back(0);

    for (int i = 1; i <= n; ++i)
    {
        int u; cin >> u;
        a[u].push_back(i);
    }

    for (int i = 1; i <= k; ++i) a[i].push_back(n + 1);

    int res = inf;

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j < a[i].size() - 1; ++j)
        {
            a[i][j] = a[i][j + 1] - a[i][j] - 1;
        }
        sort(a[i].begin(), a[i].end());

        if (a[i].size() >= 3) res = min(res, max(a[i][a[i].size() - 2] / 2, a[i][a[i].size() - 3]));
        else res = min(res, a[i][a[i].size() - 2] / 2);
    }

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

