// tram kam

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
    }

    if (m < n) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}



