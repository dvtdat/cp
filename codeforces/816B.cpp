// can mot noi tinh yeu dua loi'

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int inf = 1e9 + 7;
const int maxN = 200010;

void solve()
{
    int n, k, q; cin >> n >> k >> q;

    vector<int> p(maxN, 0);

    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        p[u]++; p[v + 1]--;
    }

    for (int i = 1; i < maxN; ++i)
    {
        p[i] += p[i - 1];
        p[i - 1] = (p[i - 1] >= k);
    }

    for (int i = 0; i < maxN; ++i)
    {
        p[i] += p[i - 1];
    }

    while (q--)
    {
        int u, v; cin >> u >> v;

        cout << p[v] - p[u - 1] << '\n';
    }


}

int main()
{
    int test = 1; //cin >> test;
    while (test--) solve();
}


