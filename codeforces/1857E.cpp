// 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve() {
    ll n; cin >> n;
    vector<ii> a(n);
    vector<ll> res(n);

    for (int i = 0; i < n;++i) {
        cin >> a[i].first; a[i].second = i;
    }

    sort(a.begin(), a.end());

    ll total = n;
    for (int i = 0; i < n; ++i) {
        total += abs(a[0].first - a[i].first);
    }
    res[a[0].second] = total;

    for (int i = 1; i < n; ++i) {
        total = total + 1LL *  (i * 2 - n) * (a[i].first - a[i - 1].first);
        res[a[i].second] = total;
    }

    for (ll i : res) cout << i << ' '; cout << '\n';
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