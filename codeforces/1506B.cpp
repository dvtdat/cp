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

int a[maxN];

void solve()
{
    int i;
    memset(a, 0, sizeof a);
    int n, k; cin >> n >> k;
    for (i = 0; i < n; ++i)
    {
        char c; cin >> c;
        if (c == '*') a[i] = 1; 
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i])
        {
            a[i] = 2; break;
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i])
        {
            a[i] = 2; break;
        }
    }

    i = 0;
    int res = 0;

    while (i < n)
    {
        if (a[i] == 2)
        {
            for (int j = i + k; j > i; --j)
            {
                if (!a[j]) continue;
                i = j - 1;
                a[j] = 2;
                break;
            }
        }
        i++;
    }
    for (int i = 0; i < n; ++i) 
    {
        // cout << a[i] << ' ';
        if (a[i] == 2) res++;
    }
    cout << res << '\n';
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

