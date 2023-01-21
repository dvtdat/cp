// "ngay hom nay cua ban nhu the nao?"

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
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

int cnt[50];

void solve()
{
    memset(cnt, 0, sizeof cnt);
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        for (int j = 0; j <= 30; ++j)
        {
            cnt[j] += ((v & (1 << j)) ? 1 : 0);
        }
    }

    ll res = 0;
    for (int i = 30; i >= 0; --i) 
    {
        cnt[i] = n - cnt[i];
        if (cnt[i] > k) continue;

        k -= cnt[i];
        res += 1LL * (1 << i);
    }

    cout << res << '\n';
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

