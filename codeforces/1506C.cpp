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
    string a, b; cin >> a >> b;

    int res = inf;
    for (int i = 0; i < b.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            string tmp(b, i, j - i + 1);
            
            for (int ii = 0; ii < a.size(); ++ii)
            {
                for (int jj = 0; jj < a.size(); ++jj)
                {
                    string tmp2(a, ii, jj - ii + 1);
                    if (tmp == tmp2) 
                        res = min(res, ii + (int)a.size() - jj - 1 + i + (int)b.size() - j - 1);
                }
            }
        }
    }

    if (res == inf) cout << a.size() + b.size() << '\n';
    else cout << res << '\n';
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

