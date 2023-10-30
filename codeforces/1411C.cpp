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

void dfs(int u, vector<int> &visited, vector<int> &adj, int &res)
{
    visited[u] = 1;
    if (adj[u] == -1)
    {
        visited[u] = 2;
        return;
    }

    if (visited[adj[u]] == 1)res++;
    else if (visited[adj[u]] == 0) dfs(adj[u], visited, adj, res);

    visited[u] = 2;
};

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> adj(n, -1);
    vector<int> visited(n, 0);

    int res = m;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        if (u == v) res--;
        else adj[u - 1] = v - 1;
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i]) continue;
        dfs(i, visited, adj, res);
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

