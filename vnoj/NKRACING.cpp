// phuong 15 : 32oC : UV index: extreme

#include <bits/stdc++.h>
#define N 100010
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
    int n, m; cin >> n >> m;

    int sum = 0;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        edge.push_back(iii(-w, ii(u, v)));
    }

    memset(par, -1, sizeof par);

    sort(edge.begin(), edge.end());
    vector<iii>::iterator it;

    int res = 0;
    for (it = edge.begin(); it != edge.end(); it++)
    {
        if (anc(it->second.first) != anc(it->second.second))
        {
            join(it->second.first, it->second.second);
            res += it->first;
        }
    }

    cout << sum + res;
}
