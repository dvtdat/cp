#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    vector<int> a(n), p(n);

    while (k--)
    {
        int u, v; cin >> u >> v;
        a[u--]++; a[v-- + 1]--;
    }

    p[0] = a[0];
    for (int i = 1; i < n; ++i) p[i] = p[i - 1] + a[i];

    sort(p.begin(), p.end());

    cout << p[n / 2] << '\n';
}
