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
const int maxN = 40010;
const ll MOD = 1000000007;
const double eps = 1e-12;

ll palin[1000], f[maxN];
int n = 0;

int rev(int x)
{
    int l = x, res = 0;
    while (l > 0)
    {
        res = res * 10 + l % 10;
        l /= 10;
    }

    return res;
}


void init()
{
    for (int i = 1; i <= 40000; ++i)
    {
        if (rev(i) == i) palin[n++] = i;
    }

    f[0] = 1; // base case
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < maxN; ++j)
        {
            if (j - palin[i] < 0) continue;
            f[j] += f[j - palin[i]];
            f[j] %= MOD;
        }
    }
}


void solve()
{
    int k; cin >> k;
    cout << f[k] % MOD << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    init();
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

