// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200000010;
const ll MOD = 998244353;
const double eps = 1e-12;

unordered_map<int, int> p;

void factor(int n) {
    int _n = n;
    for (int i = 2; i * i <= n && _n > 0; ++i) {
        while (_n % i == 0 && _n > 0) {
            _n /= i;
            if (!p[i]) p[i] = 1;
            else p[i]++;
        }
    }
    if (_n != 1) {
        if (!p[_n]) p[_n] = 1;
        else p[_n]++;
    }
}

void solve() {
    p.clear();
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        factor(u);
    }

    int total = 0;
    int left = 0;
    for (auto x : p) {
        left += x.second % 2;
        total += x.second / 2;
    }

    cout << total + left / 3 << '\n';
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

