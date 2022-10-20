#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<char> c(4);

    for (int i = 0; i < 4; ++i) cin >> c[i];

    sort(c.begin(), c.end());

    int cnt = 0;

    for (int i = 1; i < 4; ++i)
    {
        if (c[i] != c[i - 1]) cnt++;
    }

    cout << cnt << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
