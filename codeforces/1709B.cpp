#include <bits/stdc++.h>

using namespace std;

long long a[200010], p1[200010], p2[200010];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> a[i];

    p1[0] = 0;
    for (int i = 1; i < n; ++i) p1[i] = p1[i - 1] + max(0LL, a[i - 1] - a[i]);

    p2[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) p2[i] = p2[i + 1] + max(0LL, a[i + 1] - a[i]);

    while (m--)
    {
        int u, v; cin >> u >> v; u--; v--;

        if (v > u) cout << p1[v] - p1[u];
        else cout << p2[v] - p2[u];

        cout << '\n';
    }
}
