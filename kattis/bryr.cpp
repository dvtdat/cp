#include <bits/stdc++.h>
#define maxN 100010
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;

vector<ii> adj[maxN];
int d[maxN];
bool mark[maxN];
int n, m, s, t;
int u, v, w;

void dijkstra(int s)
{
    for (int i = 0; i <= n; ++i) d[i] = inf, mark[i] = false;
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));

    while (!pq.empty())
    {
        u = pq.top().second;
        pq.pop();

        if (mark[u]) continue;
        mark[u] = true;

        for (ii i : adj[u])
        {
            v = i.first;
            w = i.second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    dijkstra(1);

    cout << d[n];
}
