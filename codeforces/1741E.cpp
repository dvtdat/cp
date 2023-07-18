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
    vector<int> a(n + 1);
    vector<bool> f(n + 1, false);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    f[0] = 1; // BASE CASE: when a[0] = 0 => always true
    for (int i = 1; i <= n; ++i)
    {
        if (i + a[i] <= n) f[i + a[i]] = f[i - 1] | f[i + a[i]];    // PUSH DP
        if (i - a[i] - 1 >= 0) f[i] = f[i - a[i] - 1] | f[i];       // PULL DP
    }

    cout << (f[n] ? "YES" : "NO") << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test = 1; cin >> test;
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

