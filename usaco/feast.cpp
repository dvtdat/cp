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
    int t, a, b; cin >> t >> a >> b;
    vector<vector<int>> f(2, vector<int> (t + 10, 0));

    // PULL DP

    f[0][0] = 1; // BASE CASE: There is always way to have 0 fullness: not eating anything
    for (int i = 1; i <= t; ++i)
    {
        if (i - a >= 0) f[0][i] |= f[0][i - a];
        if (i - b >= 0) f[0][i] |= f[0][i - b];
        f[1][i / 2] |= f[0][i];
    }

    for (int i = 1; i <= t; ++i)
    {
        if (i - a >= 0) f[1][i] |= f[1][i - a];
        if (i - b >= 0) f[1][i] |= f[1][i - b];
    }

    // for (int i = 0 ; i <= t; ++i) cout << f[0][i] << ' '; cout << '\n';
    // for (int i = 0 ; i <= t; ++i) cout << f[1][i] << ' '; cout << '\n';

    do
    {
        if (!f[1][t] && !f[0][t]) continue;
        cout << t << '\n';
        return;
    }
    while (t--);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

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

