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
    int n; cin >> n;

    vector<ii> inp(n + 1);
    vector<vector<ll>> a(n + 1, vector<ll>(1, 0));

    for (int i = 0; i < n; ++i) cin >> inp[i].first;
    for (int i = 0; i < n; ++i) cin >> inp[i].second;

    for (int i = 0; i < n; ++i)     
    {
        a[inp[i].first].push_back(inp[i].second);
    }

    vector<ll> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size() == 1) continue;
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin() + 1, a[i].end());;

        vector<ll> p(a[i].size() + 1, 0);
        for (int j = 1; j <= a[i].size() - 1; ++j) p[j] = 1ll * p[j - 1] + a[i][j];
        for (int k = 1; k <= a[i].size() - 1; ++k) ans[k] += p[(a[i].size() - 1) / k * k];
    }

    for (int k = 1; k <= n; ++k) cout << ans[k] << ' ';
    cout << '\n';
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

