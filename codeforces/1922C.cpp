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

void solve() {
    ll n; cin >> n;
    vector<ll> a(n + 2), f(n + 2), g(n + 2);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    a[0] = -inf;
    a[n + 1] = inf;

    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] + (a[i - 1] - a[i - 2] < a[i] - a[i - 1] ? a[i] - a[i - 1] : 1);
    }

    for (int i = n - 1; i >= 1; --i) {
        g[i] = g[i + 1] + (a[i + 1] - a[i] > a[i + 2] - a[i + 1] ? a[i + 1] - a[i] : 1);
    }

    int m; cin >> m;
    while (m--) {
        ll u, v; cin >> u >> v;
        if (u < v) cout << f[v] - f[u] << '\n';
        else cout << g[v] - g[u] << '\n';
    }
}

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main() {
    setIO("text");
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