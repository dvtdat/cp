#include <bits/stdc++.h>
#define N 10010
#define inf INT_MAX

using namespace std;

vector<int> adj[N];
int b[N], k[N];
int mark[N][N];
int n;

int main()
{
    freopen("HUUNGHI.INP", "r", stdin);
    freopen("HUUNGHI.OUT", "w", stdout);

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        b[u]++; b[v]++;
    }

    queue<int> d;
    for (int i = 1; i <= n; ++i)
        if (b[i] == 1) d.push(i);

    for (int i = 1; i <= n; ++i) k[i] = 1;

    int cnt = 0, res = 0;

    while (!d.empty())
    {
        int u = d.front(); d.pop();

        for (int v : adj[u])
        {
            if (!mark[u][v])
            {
                mark[u][v] = mark[v][u] = true;

                b[v]--;
                if (b[v] == 1) d.push(v);

                res += k[u] * (n - k[u]);
                k[v] += k[u];

                cnt++;
                if (cnt == n - 1)
                {
                    cout << res; return 0;
                }

            }
        }
    }

    if (n == 1) cout << 0;
}
