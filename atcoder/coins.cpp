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

double p[4000];
double f[4000][4000];

void solve()
{
    memset(f, 0.0, sizeof f);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];

    f[0][1] = 1.0 - p[1];
    f[1][1] = p[1];

    for (int i = 2; i <= n; ++i) f[0][i] = f[0][i - 1] * (1.0 - p[i]);
    for (int j = 2; j <= n; ++j)
    {
        for (int i = 1; i <= j; ++i)
        {
            f[i][j] = f[i][j - 1] * (1.0 - p[j]) + f[i - 1][j - 1] * p[j]; 
        }
    }

    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j) cout << f[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << fixed << setprecision(10);
    double res = 0;
    for (int i = n; i > n / 2; --i) res += f[i][n];
    
    cout << res;
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

