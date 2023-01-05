// darkcyannnnn

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
const int maxN = 200100;
const ll MOD = 998244353;
const double eps = 1e-12;

ll n;
ll h[maxN], hMod[maxN];

bool ok(ll x)
{
    for (int i = 0; i < n; ++i) hMod[i] = h[i];

    for (int i = n - 1; i > 1; --i)
    {
        if (hMod[i] < x) return false;
        ll d = min(h[i], hMod[i] - x) / 3;
        hMod[i - 1] += d;
        hMod[i - 2] += 2 * d;
    }

    return (hMod[0] >= x && hMod[1] >= x);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];

    ll l = 1, r = 1;
    while (ok(r)) r *= 2;

    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (ok(mid)) l = mid;
        else r = mid;
    }

    cout << l << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
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


