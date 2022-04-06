// em co muon ngay nao` do' mik ra khoi

#include <bits/stdc++.h>
#define inf INT_MAX
#define N 30100

using namespace std;

typedef pair<int, int> ii;

vector<ii> adj[N];
int d1[N], d2[N];
long long c1[N], c2[N];
int n, m;

void dijkstra(int s, int *d, long long *c)
{
    for (int i = 1; i <= n; ++i) c[i] = 0, d[i] = inf;

    d[s] = 0; c[s] = 1;

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if (du > d[u]) continue;

        for (ii i : adj[u])
        {
            int v = i.first;
            int w = i.second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                c[v] = c[u];
                pq.push(ii(d[v], v));
            }
            else if (d[v] == d[u] + w) c[v] += c[u];
        }
    }
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }

    dijkstra(1, d1, c1);
    dijkstra(n, d2, c2);

    vector<int> res;

    for (int i = 1; i <= n; ++i)
    {
        if (!(d1[i] + d2[i] == d1[n] && c1[i] * c2[i] == c1[n])) res.push_back(i);
    }

    cout << res.size() << endl;
    for (int i : res) cout << i << endl;
}
