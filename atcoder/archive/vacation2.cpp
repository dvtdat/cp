//go litle rock star

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

int a[3][maxN];
int f[3][maxN];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    }

    f[0][0] = a[0][0];
    f[1][0] = a[1][0];
    f[2][0] = a[2][0];

    for (int i = 1; i < n; ++i)
    {
        f[0][i] = a[0][i] + max(f[1][i - 1], f[2][i - 1]);
        f[1][i] = a[1][i] + max(f[0][i - 1], f[2][i - 1]);
        f[2][i] = a[2][i] + max(f[0][i - 1], f[1][i - 1]);
    }

    cout << max(f[0][n - 1], max(f[1][n - 1], f[2][n - 1]));
}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.inp", "r", stdin);
        //freopen("output.out", "w", stdout);
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

