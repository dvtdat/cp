// no emotion

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int res = 0;

    if (k == 0) res = a[0] - 1;
    else res = a[k - 1];

    int cnt;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= res) cnt++;
    }

    if (cnt != k || res == 0 || res > 1000000000) cout << -1;
    else cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1; //cin >> test;
    while (test--) solve();
}

