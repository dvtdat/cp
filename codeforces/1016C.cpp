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

    vector<vector<ll>> a(2, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i) cin >> a[0][i];
    for (int i = 1; i <= n; ++i) cin >> a[1][i];

    vector<vector<ll>> pre(2, vector<ll>(n + 1, 0));
    vector<vector<ll>> suf(2, vector<ll>(n + 1, 0));
    vector<vector<ll>> sum(2, vector<ll>(n + 1, 0));
    vector<ll> f(n + 1, 0);

    for (int i = 1; i <= n; ++i) sum[0][i] = a[0][i] + sum[0][i - 1];
    for (int i = 1; i <= n; ++i) sum[1][i] = a[1][i] + sum[1][i - 1];

    for (int i = 1; i <= n; ++i) pre[0][i] = a[0][i] * i + pre[0][i - 1];
    for (int i = 1; i <= n; ++i) pre[1][i] = a[1][i] * i + pre[1][i - 1];

    suf[0][n] = a[0][n];
    suf[1][n] = a[1][n];
    for (int i = n - 1; i >= 0; --i) suf[0][i] = a[0][i] * (n - i + 1) + suf[0][i + 1];
    for (int i = n - 1; i >= 0; --i) suf[1][i] = a[1][i] * (n - i + 1) + suf[1][i + 1];

    int tog = 0; // toggle
    ll cur = 0;
    for (int i = 1; i < n; ++i)
    {
        tog = !tog;

        cur += 1LL * a[!tog][i] * (i * 2 - 2) + 1LL * a[tog][i] * (i * 2 - 1);
        ll tmp = cur;

        tmp += pre[tog][n] - pre[tog][i] + 1LL * (sum[tog][n] - sum[tog][i]) * (i - 1);
        tmp += suf[!tog][i + 1] + 1LL * (sum[!tog][n] - sum[!tog][i]) * (i + n - 1);

        f[i] = tmp;
    }
    f[n] = pre[0][n] - sum[0][n] + suf[1][0] + 1LL * sum[1][n] * (n - 1);
    
    // for (ll i : f) cout << i << ' ';
    cout << *max_element(f.begin(), f.end()) << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
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

