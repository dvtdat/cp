#include <bits/stdc++.h>
#define maxN 3000
#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> i3;

vector<i3> edge;

int par[maxN];

int anc(int p)
{
    if (par[p] == p) return p;
    return par[p] = anc(par[p]);
}

void join(int p, int q)
{
    par[anc(p)] = anc(q);
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i <= n; ++i) par[i] = i;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int w; cin >> w;
            if (i != j) edge.push_back(i3(w, ii(i, j)));
        }
    }

    sort(edge.begin(), edge.end());

    vector<ii> adj;

    for (i3 i : edge)
    {
        if (anc(i.second.first) != anc(i.second.second))
        {
            join(i.second.first, i.second.second);
            adj.push_back(ii(i.second.first, i.second.second));
        }
    }

    sort(adj.begin(), adj.end());

    for (ii i : adj)
    {
        cout << i.first << ' ' << i.second << endl;
    }
}
