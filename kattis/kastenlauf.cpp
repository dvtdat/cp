#include <bits/stdc++.h>

using namespace std;

int par[110];

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
    int test;
    cin >> test;
    while (test--)
    {
        int n; cin >> n;
        n += 2;

        for (int i = 0; i < n; ++i) par[i] = i;
        vector<pair<int, int>> coor(n);
        vector<vector<int>> f(n, vector<int> (n, INT_MAX));

        for (int i = 0; i < n; ++i) cin >> coor[i].first >> coor[i].second;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int tmp = abs(coor[i].first - coor[j].first) + abs(coor[i].second - coor[j].second);
                if (tmp <= 1000) join(i, j);
            }
        }
        cout << (anc(0) == anc(n - 1) ? "hApPy" : "sAd") << endl;

    }
}
