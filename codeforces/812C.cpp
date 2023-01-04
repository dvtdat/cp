// dont know what to think

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 100010;
const ll MOD = 998244353;
const double eps = 1e-12;

ll n, sum;
ll a[maxN], p[maxN];

ll cal(ll k)
{
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        p[i] = a[i] + (ll)((i + 1) * k);
    }

    sort(p, p + n);
    for (int i = 0; i < k; ++i) cnt += p[i];

    return cnt;
}

void solve()
{
    cin >> n >> sum;
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll l = 0, r = n + 1;

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (cal(mid) <= sum) l = mid;
        else r = mid;
    }

    cout << l << ' ' << cal(l);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//


