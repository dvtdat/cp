// Bi sex ua(l)

#include <bits/stdc++.h>
#define N 100100

using namespace std;

typedef pair<int, int> ii;

int f[N];
vector<int> adj[N];

int dfs(int s)
{
    if (f[s]) return f[s];
    else for (int i : adj[s])
    {
        f[i] = dfs(i);
        f[s] = max(f[s], f[i] + 1);
    }

    return f[s];
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) dfs(i);

    int res = 0;
    for (int i = 1; i <= n; ++i) res = max(res, f[i]);

    cout << res;
}

