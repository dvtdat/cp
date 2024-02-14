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
    int n; cin >> n;
    vector<vector<ll>> v(n);
    vector<ll> a;

    int mn = inf;
    int idx = -1;
    ll total = 0;

    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        v[i] = vector<ll>(m);
        for (ll &x : v[i]) cin >> x;
        sort(v[i].begin(), v[i].end());

        if (v[i][1] < mn) {
            idx = i;
            mn = v[i][1];
        }
        total += v[i][1];
        
        a.push_back(v[i][0]);
    }

    total -= v[idx][1];
    total += *min_element(a.begin(), a.end());

    cout << total << '\n';
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

