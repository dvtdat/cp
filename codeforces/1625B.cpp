//ke that bai xu An Nam

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void solve()
{
    int n; cin >> n;
    vector<ii> a(n);
    int tmp;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        a[i] = ii(tmp, i);
    }

    sort(a.begin(), a.end());

    int mn = INT_MAX;
    for (int i = 1; i < n; ++i)
    {
        if (a[i].first == a[i - 1].first)
        {
            mn = min(mn, abs(a[i].second - a[i - 1].second));
        }
    }

    if (mn != INT_MAX) cout << n - mn << '\n';
    else cout << -1 << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
