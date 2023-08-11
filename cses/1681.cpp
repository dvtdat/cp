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

int visited[maxN];
vector<int> adj[maxN];
vector<int> topo;

void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (visited[v] == 0) dfs(v);
    }
    topo.push_back(u);    
}

void solve()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i]) dfs(i);
    }

    reverse(topo.begin(), topo.end());

    vector<ll> f(n, 0);
    f[0] = 1;
    for (int u : topo)
    {
        for (int v : adj[u])
        {
            f[v] = (f[u] % MOD + f[v] % MOD) % MOD;
        }
    }

    cout << f[n - 1];
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

