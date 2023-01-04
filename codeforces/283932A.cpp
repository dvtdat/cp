//

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

bool ok(ll x, ll a, ll b, ll n)
{
    return ((x / a) * (x / b) >= n);
}

void solve()
{
    ll a, b, n; cin >> a >> b >> n;

    ll l = 0, r = 1;
    while (!ok(r, a, b, n)) r *= 2;

    while (r - 1 > l)
    {
        ll mid = (l + r) / 2;
        if (ok(mid, a, b, n)) r = mid;
        else l = mid;
    }

    cout << r;
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
