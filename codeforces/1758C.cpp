// that feeling.

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

int res[maxN];

void solve()
{
    memset(res, 0, sizeof res);

    int n, k; cin >> n >> k;

    if (n % k != 0)
    {
        cout << "-1\n"; return;
    }

    for (int i = 1; i <= n; ++i) res[i] = i;

    vector<int> exc;

    exc.push_back(k); res[k] = -1;
    for (int i = 2; i <= n / k + 1; ++i)
    {
        if ((i * k) % exc[exc.size() - 1] == 0 && n % (i * k) == 0)
        {
            exc.push_back(i * k);
            res[i * k] = -1;
        }
    }

    res[n] = 1; res[1] = k;

    int cnt = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (res[i] == -1) res[i] = exc[cnt++];
        cout << res[i] << ' ';
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

