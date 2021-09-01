#include <bits/stdc++.h>
#define maxN 10100
#define ll long long

using namespace std;

typedef pair<ll, ll> ii;

ll u, v, w;

bool vis[maxN];
vector<ii> adj[maxN];

ll bfs(vector<ll> s)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (auto i : s)
    {
        for (auto j : adj[i]) pq.push(j);
    }

    ll res = 0;

    while (!pq.empty())
    {
        u = pq.top().second;
        w = pq.top().first;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        res += w;

        for (auto i : adj[u]) pq.push(i);
    }

    return res;
}

int main()
{
    int test; cin >> test;
    while (test--)
    {
        ll n, m, l, st;
        cin >> n >> m >> l >> st;

        for (int i = 0; i < maxN; ++i) adj[i].clear(), vis[i] = false;

        vector<ll> s;

        for (int i = 1; i <= st; ++i)
        {
            ll tmp; cin >> tmp;
            vis[tmp]= true;
            s.push_back(tmp);
        }

        while (m--)
        {
            cin >> u >> v >> w;
            adj[u].push_back(ii(w + l, v));
            adj[v].push_back(ii(w + l, u));
        }

        cout << bfs(s) << endl;
    }
}
