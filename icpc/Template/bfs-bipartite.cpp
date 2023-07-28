/*
    Description: https://cses.fi/problemset/task/1668
*/

#include <bits/stdc++.h>

using namespace std;

const int maxN = 200010;

vector<int> adj[maxN];
bool visited[maxN];
int d[maxN];

bool bfs(int s)
{
    queue<int> q; q.push(s);
    d[s] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (int v : adj[u])
        {
            if (visited[v]) continue;
            d[v] = (d[u] + 1) % 2;
            q.push(v);
        }

        for (int v : adj[u])
        {
            if (d[v] == d[u]) return false;
        }
    }
    return true;
}

int main()
{
    memset(d, -1, sizeof d);
    memset(visited, false, sizeof visited);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v; 
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i]) continue;
        if (bfs(i)) continue;
        cout << "IMPOSSIBLE\n"; return;
    }

    for (int i = 0; i < n; ++i) cout << d[i] + 1 << ' ';
}