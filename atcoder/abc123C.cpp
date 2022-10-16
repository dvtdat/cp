#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n + 5), pre(n + 5), suf(n + 5);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    pre[0] = 0; suf[n + 1] = 0;

    for (int i = 1; i <= n; ++i) pre[i] = __gcd(pre[i - 1], a[i]);
    for (int i = n; i >= 1; --i) suf[i] = __gcd(suf[i + 1], a[i]);

    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res = max(res, __gcd(pre[i - 1], suf[i + 1]));
    }

    cout << res;
}
