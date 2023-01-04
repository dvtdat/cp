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
const double eps = 1e-6;

int rope[maxN];
int n, k;

bool ok(ld x)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += (int)(1.0 * rope[i] / x);
    return (cnt >= k);
}

void solve()
{
    cout << fixed << setprecision(6);
    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> rope[i];

    ld l = 0, r = 100000000.01;

    for (int i = 0; i < 100; ++i)
    {
        ld mid = (l + r) / 2;
        if (ok(mid)) l = mid; else r = mid;
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


