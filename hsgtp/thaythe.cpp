#include <bits/stdc++.h>
#define inf INT_MAX
#define N 1000010

using namespace std;

typedef pair<int, int> ii;

int n, p, a, b, r;
int d[N];
vector<int> adj[N];

int bfs()
{
    for (int i = 0; i <= p; ++i) d[i] = inf; d[p] = 0;
    queue<int> q; q.push(p);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : adj[u])
        {
            if (d[v] == inf)
            {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> p >> a >> b >> r;

    for (int u = 0; u < p; ++u)
    {
        adj[u].push_back((u + a) % p);
        adj[u].push_back((u + b) % p);
        adj[u].push_back((u + a + b) % p);
    }

    adj[p].push_back((n + a) % p);
    adj[p].push_back((n + b) % p);
    adj[p].push_back((n + a + b) % p);

    bfs();

    if (d[r] == inf) cout << -1;
    else cout << d[r];
}
