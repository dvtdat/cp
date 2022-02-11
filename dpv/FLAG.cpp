#include <bits/stdc++.h>
#define inf 1e9+7
#define maxN 210

using namespace std;

int a[maxN][maxN];
int u, v, w;

int main()
{
    freopen("FLAG.inp","r",stdin);
    freopen("FLAG.out","w",stdout);

    int n, m;
    int p, q;

    cin >> n >> m >> p >> q;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i != j) a[i][j] = inf; else a[i][j] = 0;
        }
    }

    while (m--)
    {
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                if (a[i][j] > a[i][k] + a[k][j]) a[i][j] = a[i][k] + a[k][j];
        }
    }

    vector<int> rA, rB;

    for (int i = 1; i <= n; ++i)
    {
        if (a[p][i] < a[q][i]) rA.push_back(i);
        else if (a[p][i] == a[q][i]) rB.push_back(i);
    }

    sort(rA.begin(), rA.end());
    sort(rB.begin(), rB.end());

    cout << rA.size() << endl;
    for (int i = 0; i < rA.size(); ++i) cout << rA[i] << ' '; cout << endl;

    cout << rB.size() << endl;
    for (int i = 0; i < rB.size(); ++i) cout << rB[i] << ' '; cout << endl;
}

