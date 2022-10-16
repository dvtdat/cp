#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, b, k; cin >> n >> k >> b;

    vector<int> p(n + 5, 0), a(n + 5, 0);

    for (int i = 0; i < b; ++i)
    {
        int tmp; cin >> tmp; tmp--;
        a[tmp]++;
    }

    for (int i = 0; i < n; ++i) p[i + 1] = a[i + 1] + p[i];

    int res = INT_MAX;
    for (int i = 0; i <= n - k; ++i)
    {
        res = min(res, p[i + k] - p[i]);
    }

    cout << res;
}
