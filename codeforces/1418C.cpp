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
    int n; cin >> n;

    vector<int> a(n + 5);
    vector<array<int, 2>> f(n + 5, {inf, inf});

    for (int i = 0; i < n; ++i) cin >> a[i];

    // PUSH DP

    f[0][1] = 0; // BASE CASE: when my friend fight first boss without skip point

    // f[i][0] is current state of me
    // f[i][1] is current state of my friend

    for (int i = 0; i < n; ++i)
    {
        f[i + 1][0] = min(f[i + 1][0], f[i][1] + a[i]);
        f[i + 2][0] = min(f[i + 2][0], f[i][1] + a[i] + a[i + 1]);
        f[i + 1][1] = min(f[i + 1][1], f[i][0]);
        f[i + 2][1] = min(f[i + 2][1], f[i][0]);
    }

    cout << min(f[n][0], f[n][1]) << '\n';
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

