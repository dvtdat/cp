#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    map<int, ii> m;

    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;

        if (!m.count(u))
        {
            m[u].first = i;
            m[u].second = i;
        }
        else m[u].second = i;
    }

    while (q--)
    {
        int u, v; cin >> u >> v;
        if (!m.count(u) || !m.count(v) || m[u].first > m[v].second) cout << "no\n";
        else cout << "yes\n";
    }
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}

