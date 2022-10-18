#include <bits/stdc++.h>

using namespace std;

int fac(int n)
{
    int res = 1;
    for (int i = 2; i <= n; ++i) res *= i;

    return res;
}

void solve()
{
    int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    n = 10 - n;

    cout << 6 * (fac(n) / (2 * fac(n - 2))) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while (test--) solve();
}
