// ai noi ta dai kho`?

#include <bits/stdc++.h>
#define N 210
#define inf 2e9

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

vvii g1, g2, g3, g4;
int d[5][N];
int n, m;

void dijkstra(const vvii &adj, int *d, const int &s)
{
    for (int i = 0; i <= n; ++i) d[i] = inf;
    d[s] = 0;
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0, s));

    while (!pq.empty())
    {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (du > d[u]) continue;

        for (ii i : adj[u])
        {
            int v = i.first;
            int w = i.second;
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
    freopen("meeting.in", "r", stdin);
    freopen("meeting.out", "w", stdout);
    cin >> n >> m;

    g1 = vvii(n + 10, vii());
    g2 = vvii(n + 10, vii());
    g3 = vvii(n + 10, vii());
    g4 = vvii(n + 10, vii());

    while (m--)
    {
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;

        g1[u].push_back(ii(v, w1));
        g2[v].push_back(ii(u, w1));
        g3[u].push_back(ii(v, w2));
        g4[v].push_back(ii(u, w2));
    }

    dijkstra(g1, d[1], 1);
    dijkstra(g2, d[2], n);
    dijkstra(g3, d[3], 1);
    dijkstra(g4, d[4], n);

    int res = inf;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((d[1][i] != inf) && (d[2][i] != inf) &&
                (d[3][j] != inf) && (d[4][j] != inf) &&
                d[1][i] + d[2][i] == d[3][j] + d[4][j])
                res = min(res, d[1][i] + d[2][i]);
        }
    }

    if (res < inf) cout << res; else cout << "IMPOSSIBLE";
}
