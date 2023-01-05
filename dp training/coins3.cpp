// lam lai cuoc doi nao`

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
    /* Given a set of N types of coin, each have a value of a_i, 
    how many way are there to get a sum of the value of K */

    int n, k; cin >> n >> k;

    vector<int> coins(n), value(k + 1);

    for (int &coin : coins) cin >> coin;
    
    value[0] = 1; // BASE CASE
    for (int sum = 1; sum <= k; ++sum)
    {
        for (int coin : coins)
        {
            if (sum - coin < 0) continue;
            value[sum] += value[sum - coin];
            value[sum] %= MOD;
        }
    }

    cout << value[k];
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

