// ma` thoi ong oi

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
    
    if (a.length() > b.length()) swap(a, b);

    int len1 = a.length(), len2 = b.length();

    int m = len1 * len2 / __gcd(len1, len2);
    string tmpA = a, tmpB = b;

    for (int i = 0; i < m / len1 - 1; ++i) tmpA += a; a = tmpA;
    for (int i = 0; i < m / len2 - 1; ++i) tmpB += b; b = tmpB;

    if (a != b)
    {
        cout << -1 << '\n'; return;
    }

    int n = __gcd(len1, len2);

    for (int i = 0; i < m / n; ++i)
    {
        for (int j = 0; j < __gcd(len1, len2); ++j) cout << a[j];
    }

    cout << '\n';
    


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

