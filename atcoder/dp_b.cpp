// 

#include <bits/stdc++.h>

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
    int n, k; cin >> n >> k;

    vector<int> h(n), f(n + k, inf);
    for (int i = 0; i < n; ++i) cin >> h[i];

    // PUSH DP
    f[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (i + j < n) f[i + j] = min(f[i + j], f[i] + abs(h[i] - h[i + j]));
        }
    }

    cout << f[n - 1] << '\n';
    // for (int i = 0; i < n; ++i) cout << f[i] << ' ';
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

