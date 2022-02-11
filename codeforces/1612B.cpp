//toi that bai

#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

void solve()
{
    int n, a, b; cin >> n >> a >> b;

    vector<int> v;
    v.push_back(a);
    for (int i = n / 2 + 1; i <= n; ++i)
        if (i != a && i != b) v.push_back(i);

    v.push_back(b);
    for (int i = 1; i <= n / 2; ++i)
        if (i != a && i != b) v.push_back(i);

    int mn = inf, mx = 0;

    for (int i = 0; i < n / 2; ++i) mn = min(mn, v[i]);
    for (int i = n / 2; i < n; ++i) mx = max(mx, v[i]);

    if (v.size() == n && mn == a && mx == b) for (int i = 0; i < n; ++i) cout << v[i] << ' ';
    else cout << -1;

    cout << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}


