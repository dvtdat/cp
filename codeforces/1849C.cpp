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
    int n, m; cin >> n >> m;
    set<ii> _set;

    string s; cin >> s;
    vector<int> l(n + 10), r(n + 1);

    if (s[n - 1] == '1') l[n - 1] = n - 1; else l[n - 1] = inf;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == '1') l[i] = i;
        else l[i] = l[i + 1];
    }

    if (s[0] == '0') r[0] = 0; else r[0] = -1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '0') r[i] = i;
        else r[i] = r[i - 1];
    }

    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        if (r[v] > l[u]) _set.insert({l[u], r[v]});
        else _set.insert({-1, -1});
    }

    cout << _set.size() << '\n';
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