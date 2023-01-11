// noisy af

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

bool f[maxN * 100];
int weights[maxN];

void solve()
{
    /*  Given a list of weights, determine all sums that can be 
        constructed using the weights
        
        This is similar to knapsack1.cpp, but with limited memory 
        and can only use one-dimension array */

    int n, maxW; cin >> n >> maxW;

    memset(f, false, sizeof f);

    for (int i = 1; i <= n; ++i) cin >> weights[i];

    f[0] = true; // BASE CASE

    for (int k = 1; k <= n; ++k)
    {
        for (int x = maxW; x >= 0; x--)
        {
            if (f[x]) f[x + weights[k]] = true;
        }
    }

    for (int x = 1; x <= maxW; ++x) cout << f[x] << ' ';
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

