// vang trang khoc - nhat tinh anh ft. khanh ngoc

#include <bits/stdc++.h>
#define N 5100
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;

vector<ii> adj[N];
long long d[N], c[N];
int n, m;

void dijkstra(int s)
{
    for (int i = 1; i <= n; ++i) d[i] = inf, c[i] = 0;

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
        int u, v, k, w;
        cin  >> k >> u >> v >> w;
        adj[u].push_back(ii(v, w));

        if (k == 2) adj[v].push_back(ii(u, w));
    }

    dijkstra(1);

    cout << d[n] << ' ' << c[n];

}
