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
    vector<int> s;
    vector<vector<int>> ans(n + 1, vector<int>());
    vector<int> visited(n + 1, 0);
    vector<int> par(n + 1, -1);

    for (int i = 1; i <= n; ++i)
    {
        int u; cin >> u;
        visited[u] = 1;
        par[i] = u;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i]) s.push_back(i);
    }
    visited = vector<int>(n + 1, 0);

    int res = 0;
    int u = -1;

    for (int ss : s)
    {
        u = ss;
        while (u != par[u] && !visited[par[u]])
        {
            ans[res].push_back(u);
            visited[u] = 1;
            u = par[u];
        }
        ans[res].push_back(u);
        visited[u] = 1;
        reverse(ans[res].begin(), ans[res].end());
        res++;
    }

    if (n == 1)
    {
        cout << 1 << '\n' << 1 << '\n' << 1 << '\n' << '\n';
        return;
    }

    cout << res << '\n';
    for (int i = 0; i < res; ++i)
    {
        cout << ans[i].size() << '\n';
        for (int u : ans[i]) cout << u << ' '; cout << '\n';
    }
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

