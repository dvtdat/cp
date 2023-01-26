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

int a[maxN];

void solve()
{
    int n, k; cin >> n >> k;
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        a[i] = c - '0';
        if (a[i]) res++;
    }

    res *= 11;

    int l = 0, r = n - 1;
    while (l < n && a[l] != 1) l++;
    while (r >= 0 && a[r] != 1) r--;

    if (r < l)
    {
        cout << "0\n"; return;
    }

    if (l == r)
    {
        if (n - r - 1 <= k) cout << "1\n";
        else if (l <= k) cout << "10\n";
        else cout << "11\n";
        return;
    }
    
    if (n - r - 1 <= k)
    {
        res -= 10; k -= (n - r - 1);
    }

    if (l <= k)
    {
        res -= 1;
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

