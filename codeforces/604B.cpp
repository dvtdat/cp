// nguoi ta khong yeu m dau, cho` doi. lam j

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int inf = 1e9 + 7;
const int maxN = 200010;

void solve()
{
    long long n, k, mx = 0; cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for (int i = 0; i < n - k; ++i)
    {
        mx = max(mx, a[i] + a[n - (2 * k - n) - 1 - i]);
    }

    cout << mx;
}

int main()
{
    int test = 1; //cin >> test;
    while (test--) solve();
}



