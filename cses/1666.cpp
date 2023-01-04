//sweater weather?

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

vector<int> adj[maxN];
bool visited[maxN];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v]) dfs(v);
    }
}

void solve()
{
    int n, m, u, v; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            res.push_back(i + 1);
            dfs(i);
        }
    }

    cout << res.size() - 1 << '\n';
    for (int i = 0; i < (int)res.size() - 1; ++i)
    {
        cout << res[i] << ' ' << res[i + 1] << '\n';
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

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

