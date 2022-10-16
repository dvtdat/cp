#include <bits/stdc++.h>
#define inf INT_MAX
#define maxN 200010

using namespace std;

void solve()
{
    int n, x; cin >> n >> x;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    int mn = a[0], mx = a[0], res = 0;
    for (int i = 1; i < n; ++i)
    {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);

        if (mx - mn > x * 2)
        {
            res++; mx = a[i], mn = a[i];
        }
    }

    cout << res << '\n';
}

int main()
{
    int test; cin >> test;
    while (test--) solve();
}
