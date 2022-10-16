#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;

    vector<int> h(n + 1, 0), p(n + 1, 0), s(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        char c; cin >> c;
        if (c == 'H') h[i] = 1;
        else if (c == 'P') p[i] = 1;
        else s[i] = 1;

        h[i] += h[i - 1];
        p[i] += p[i - 1];
        s[i] += s[i - 1];
    }

    int res = 0;

    for (int i = 1; i <= n; ++i)
    {
        res = max(res, h[i] + p[n] - p[i]);
        res = max(res, h[i] + s[n] - s[i]);

        res = max(res, p[i] + h[n] - h[i]);
        res = max(res, p[i] + s[n] - s[i]);

        res = max(res, s[i] + p[n] - p[i]);
        res = max(res, s[i] + h[n] - h[i]);
    }

    cout << res;

}
