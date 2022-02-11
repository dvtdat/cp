#include <bits/stdc++.h>
#define maxN 150
#define inf INT_MAX

using namespace std;

int n, m, u, v, s, w;
vector<int> adj[maxN];
int d[maxN];

void bfs(int s, int w)
{
    int cnt = 0;
    for (int i = 0; i < maxN; ++i) d[i] = inf;
    queue<int> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (v : adj[u])
        {
            if (d[v] == inf)
            {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) if (d[i] <= w) cnt++;
    cout << n - cnt << '\n';
}

int main()
{
    freopen("GOITIN.INP", "r", stdin);
    freopen("GOITIN.OUT", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (cin >> s >> w)
    {
        if (s == 0 && w == 0) break;
        bfs(s, w);
    }
}
