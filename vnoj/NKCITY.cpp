// and live while we're young

#include <bits/stdc++.h>
#define N 1010
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int par[N];
vector<iii> edge;

int anc(int u)
{
    return par[u] < 0 ? u : par[u] = anc(par[u]);
}

void join(int u, int v)
{
    par[anc(u)] = anc(v);
}

int main()
{
    memset(par, -1, sizeof par);

    int n, m; cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back(iii(w, ii(u, v)));
    }

    sort(edge.begin(), edge.end());

    vector<iii>::iterator it;

    int res = 0;
    for (it = edge.begin(); it != edge.end(); ++it)
    {
        if (anc(it->second.first) != anc(it->second.second))
        {
            join(it->second.first, it->second.second);
            res = max(res, it->first);
        }
    }

    cout << res;
}
