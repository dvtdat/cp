#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), u(n), p(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    p[0] = a[0];
    for (int i = 1; i < n; ++i) p[i] = a[i] + p[i - 1];

    for (int i = 0; i < n; ++i) u[i] = p[i] - k * i;

    //for (int i = 0; i < n; ++i) cout << u[i] << ' ';

    map<int, int> _map;

    int mx = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!_map.count(u[i]))_map[u[i]] = i;
        else mx = max(mx, abs(_map[u[i]] - i));
    }

    cout << mx;
}
