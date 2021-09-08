#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int& i : a) cin >> i;

    long long mx = 0;
    for (int i = 0; i < n - 1; ++i) mx = max(mx, 1LL * a[i] * a[i + 1]);

    cout << mx << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}

