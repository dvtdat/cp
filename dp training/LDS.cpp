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
    /* Find the longest decreasing subsequence in the given array of integer */

    int n; cin >> n;
    vector<int> value(n), length(n);

    for (int &i : value) cin >> i;

    for (int index = 0; index < n; ++index)
    {
        length[index] = 1;
        for (int prev = 0; prev < index; ++prev)
        {
            if (value[prev] > value[index])
                length[index] = max(length[index], length[prev] + 1);
        }
    }

    int result = 0;
    for (int i : length) result = max(result, i);
    cout << result;
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

