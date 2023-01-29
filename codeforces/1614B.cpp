// the other side of the tunnel.

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

ii a[maxN];
ll pos[maxN];

void solve()
{
    memset(a, 0LL, sizeof a);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first; a[i].second = i + 1;
    }

    sort(a, a + n);
    reverse(a, a + n);

    ll cnt = 1;
    ll res = 0;
    for (int i = 0; i < n; i += 2)
    {
        pos[a[i].second] = cnt; pos[a[i + 1].second] = -cnt;
        res += a[i].first * cnt + a[i + 1].first * cnt;
        cnt++;
    }

    cout << res * 2 << '\n';
    cout << 0 << ' ';
    for (int i = 1; i <= n; ++i) cout << pos[i] << ' ';

    cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
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

