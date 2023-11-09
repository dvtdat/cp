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

vector<vector<int>> f(1010, vector<int>());

void process() {
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (__gcd(i, j) == 1) f[i].push_back(j);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int tmp =  a[0];
    for (int i = 1; i < n; ++i) {
        tmp = __gcd(tmp, a[i]);
    }

    // if (tmp != 1) {
    //     cout << -1 << '\n'; return;
    // }

    vector<int> p(1010, 0);

    for (int i = 0; i < n; ++i) {
        p[a[i]] = max(p[a[i]], i + 1);
    }

    int res = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (p[i] == 0) continue;
        for (int v : f[i]) {
            if (p[v] == 0) continue;
            res = max(res, p[v] + p[i]);
        }
    } 

    cout << (res != 0 ? res : -1) << '\n';
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
    process();
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

