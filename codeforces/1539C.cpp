//toi ngheo`

#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    ll n, k, x; cin >> n >> k >> x;

    vector<ll> a(n);
    for(ll& i : a) cin >> i;

    sort(a.begin(), a.end());

    vector<ll> b;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i - 1] > x) b.push_back((a[i] - a[i - 1] - 1) / x);
    }

    sort(b.begin(), b.end());

    int i = 0;
    while (i < b.size() && b[i] <= k)
    {
        k -= b[i++];
    }

    cout << b.size() - i + 1 << endl;
}

int main()
{
    int test; test = 1;
    while (test--) solve();
}
