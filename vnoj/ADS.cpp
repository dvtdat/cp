#include <bits/stdc++.h>
#define N 10000
#define inf INT_MAX

using namespace std;

vector<int> adj[N];
int mark[N];
int n, m;

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!mark[v])
            {
                mark[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(mark, false, sizeof mark);
    int cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!mark[i])
        {
            cnt++;
            bfs(i);
        }
    }

    cout << m - n + cnt;
}
