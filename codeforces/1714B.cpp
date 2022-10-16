#include <bits/stdc++.h>

using namespace std;

int a[200010];

void solve()
{
    int n; cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int flag = true;

    set<int> s;

    for (int i = n - 1; i >= 0; --i)
    {
        if (s.count(a[i]))
        {
            cout << i + 1 << '\n';
            return;
        }

        s.insert(a[i]);
    }

    cout << 0 << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
