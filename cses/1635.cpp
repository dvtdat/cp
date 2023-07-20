// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 1e9 + 7;
const int maxN = 2000010;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

ll a[maxN];
ll f[maxN];

void solve()
{
    for (int i = 0; i < maxN; ++i) a[i] = 0, f[i] = 0;

    ll n; cin >> n;
    ll k; cin >> k;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    // PUSH DP

    f[0] = 1; // BASE CASE: only 1 way to have sum of 0.
    for (ll i = 0; i <= k; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            f[i + a[j]] += f[i];
            f[i + a[j]] %= MOD;
        }
    }

    cout << f[k] % MOD << '\n';
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

