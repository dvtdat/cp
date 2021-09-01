#include <bits/stdc++.h>
#define ll long double

using namespace std;

typedef pair<ll, ll> ii;

int main()
{
    int n; cin >> n;
    vector<ii> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());

    ll res = -INT_MAX * 1.0;
    for (int i = 0; i < n - 1; ++i)
    {
        res = max(res, (ll)abs((a[i + 1].second - a[i].second) /
                                (a[i + 1].first - a[i].first)));
    }

    cout << fixed << setprecision(10) << res;
}
