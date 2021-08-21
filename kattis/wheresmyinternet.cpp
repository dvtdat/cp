#include <bits/stdc++.h>
#define maxN 200010

using namespace std;

int par[maxN];

int anc(int p)
{
    if (par[p] == p) return p;
    else return par[p] = anc(par[p]);
}

void join(int p, int q)
{
    par[anc(p)] = anc(q);
}

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) par[i] = i;

    while (m--)
    {
        int u, v; cin >> u >> v;
        if (anc(u) != anc(v)) join(u, v);
    }

    int tmp = anc(1);
    int cnt = 0;

    for (int i = 1; i <= n; ++i) if (anc(i) != tmp) cout << i << endl, cnt++;
    if (!cnt) cout << "Connected";
}
