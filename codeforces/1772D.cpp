// mung` 30 tet thit. treo trong nha`

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
const int inf = 2e9;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

int a[maxN];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int upper = inf / 2, lower = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] < a[i + 1])
        {
            upper = min(upper, (a[i] + a[i + 1]) / 2);
        }
        else if (a[i] > a[i + 1])
        {
            lower = max(lower, (a[i] + a[i + 1] + 1) / 2 );
        }
    }

    if (upper < lower) cout << "-1\n";
    else cout << upper << '\n';

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

