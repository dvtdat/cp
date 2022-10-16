#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.rbegin(), a.rend());

    int cnt = a[0] * 2 + 1;

    for (int i = 1; i < n; ++i)
    {
        if (cnt >= m)
        {
            cout << "no\n"; return;
        }
        cnt += a[i] + 1;
    }

    cout << "yes\n";
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
