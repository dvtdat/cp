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
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n, k; cin >> n >> k;
    ll sum = 0;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        sum += a[i] / k;
        a[i] %= k;
    }

    sort(a.begin(), a.end());

    int j = 0;
    for (int i = n - 1; i > j; --i)
    {
        while (a[i] + a[j] < k && i > j) j++; 
        if (i == j) break;
        sum++; j++;
    }


    cout << sum << '\n';
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

