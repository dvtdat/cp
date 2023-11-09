// nhac giut giut

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

ld H, X;

ld getLen(ld h, ld x) {
    return 1.0 * ((1.0 * X - x) / ((1.0 * H / h) - 1));
}

ld getHeightAt(ld p, ld h, ld x, ld x0) {
    double d1 = x - p, d0 = x0 - p;
    return 1.0 * h * d0 / d1;
}

void solve() {
    int n; cin >> n;
    vector<ld> h(n), x(n);
    vector<pair<ld, ld>> inp(n);
    for (int i = 0; i < n; ++i) cin >> inp[i].second >> inp[i].first;
    sort(inp.begin(), inp.end());
    for (int i = 0; i < n; ++i) {
        h[i] = inp[i].second;
        x[i] = inp[i].first;
    }
    cin >> H >> X;

    ld total = 0;
    for (int i = n - 1; i > 0; --i) {
        ld len = getLen(h[i], x[i]);
        ld hNext = getHeightAt(x[i] - len, h[i], x[i], x[i - 1]);
        
        if (x[i] - len >= x[i - 1]) {
            total += len * h[i];
            continue;
        }

        h[i - 1] = max(h[i - 1], hNext);
        total += len * h[i] - (len - (x[i] - x[i - 1])) * hNext;
    }

    total += getLen(h[0], x[0]) * h[0];

    cout << fixed << setprecision(6);
    cout << total * 0.5;
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

