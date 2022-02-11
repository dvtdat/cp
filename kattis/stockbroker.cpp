#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n; cin >> n;

    vector<ll> a(n);
    for (ll& i : a) cin >> i;

    ll res = 100;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1]) res += min(res / a[i - 1], 1LL * 100000) * (a[i] - a[i - 1]);
    }

    cout << res;
}
