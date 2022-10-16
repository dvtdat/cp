#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;
    vector<long long> a(n + 1), p(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    p[1] = a[1];
    for (int i = 2; i <= n; ++i) p[i] = (p[i - 1] + a[i]) % 7;

    map<int, int> m;
    int res = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!m.count(p[i]))
        {
            m[p[i]] = i;
        }
        else res = max(res, i - m[p[i]]);
    }

    cout << res;
}
