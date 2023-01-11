// sadge catto noice

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
const int maxN = 2010;
const ll MOD = 998244353;
const double eps = 1e-12;

int val[maxN][maxN], f[maxN][maxN];

void solve()
{
    /* Given a set of matrix with fixed integer value, what is the optimal way
        to maneuver through the matrix from (1, 1) to (n, n) with 2 only possible move
        from a cell is to the cell below or on the right of it.
        
        Calculate the largest sum that we can get from the given statement. */
    int n; cin >> n;

    memset(val, 0, sizeof val);
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) cin >> val[i][j];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            f[i][j] = val[i][j] + max(f[i][j - 1], f[i - 1][j]);
        }
    }

    cout << f[n][n];
    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
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
