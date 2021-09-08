#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<ll, ll> ii;

int main()
{
    ll n, k; cin >> n >> k;
    vector<ii> a, b;

    for (int i = 0; i < n; ++i)
    {
        ll u, w; cin >> u >> w;

        if (u < 0) a.push_back(ii(-u, w));
        else b.push_back(ii(u, w));
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll res = 0;

    ll i = a.size() - 1;
    while (i >= 0 && i <= n)
    {
        res += a[i].first * 2;
        ll cap = k;
        for (int j = i; j >= 0; j--)
        {
            if (cap >= a[i].second) cap -= a[i].second, i--;
            else
            {
                a[i].second -= cap;
                break;
            }
        }
    }

    i = b.size() - 1;
    while (i >= 0 && i <= n)
    {
        res += b[i].first * 2;
        ll cap = k;
        for (int j = i; j >= 0; j--)
        {
            if (cap >= b[i].second) cap -= b[i].second, i--;
            else
            {
                b[i].second -= cap;
                break;
            }
        }
    }

    cout << res;

}
