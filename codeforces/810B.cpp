// which side will i be on?

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k; cin >> n >> k;

    vector<long long> c;

    long long res = 0;

    for (int i = 0; i < n; ++i)
    {
        long long u, v; cin >> u >> v;

        res += min(u, v);
        c.push_back(min(2 * u, v) - min(u, v));
        //cout << min(2 * u, v) - min(u, v) << ' ' << res << '\n';
    }

    sort(c.rbegin(), c.rend());

    for (int i = 0; i < k; ++i) res += c[i];

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

