#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m; cin >> n >> m;

    int mn = 10000, sum = 0, cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int tmp; cin >> tmp;
            if (tmp < 0) cnt++;
            tmp = abs(tmp);
            sum += tmp; mn = min(mn, tmp);
        }
    }

    if (cnt & 1) cout << sum - 2 * mn << '\n';
    else cout << sum << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
