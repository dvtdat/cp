//discord?

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
const int maxN = 200100;
const ll MOD = 998244353;
const double eps = 1e-12;

int a[100];

void solve()
{
    int n; cin >> n;
    memset(a, 0, sizeof a);

    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        a[u]++;
    }

    for (int i = 0; i < 100; ++i)
    {
        if (a[i] == n)
        {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";

    for (int i = 0; i < 100; ++i)
    {
        if (a[i])
        {
            cout << i << ' '; a[i]--; break;
        }
    }

    for (int i = 100; i > 0; --i)
    {
        while (a[i] > 0)
        {
            cout << i << ' '; a[i]--;
        }
    }
    cout << '\n';
}

int main()
{
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


