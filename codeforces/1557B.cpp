#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int cnt = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i].second + 1 != a[i + 1].second) cnt++;
    }

    cout << (cnt <= k ? "Yes" : "No") << endl;
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
