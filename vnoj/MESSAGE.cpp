//keep on going

#include <bits/stdc++.h>
#define N 1000
#define inf INT_MAX

using namespace std;

vector<int> adj[N];
int n, m;
int mark[N], vs[N];

void bfs(int s)
{
    vs[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (int v : adj[u])
        {
            if (!vs[v])
            {
                q.push(v);
                vs[v] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(mark, false, sizeof mark);
    memset(vs, false, sizeof vs);
    int cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!vs[i]) bfs(i), mark[i] = true;
    }

    memset(vs, false, sizeof vs);

    for (int i = n; i > 0; --i)
    {
        if (!vs[i] && mark[i]) bfs(i), cnt++;
    }

    cout << cnt;
}
