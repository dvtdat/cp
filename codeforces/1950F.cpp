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
    int a, b, c; cin >> a >> b >> c;
    
    if (a + 1 != c) {
        cout << -1 << '\n'; return;
    }

    if (a == 0) {
        cout << b << '\n'; return;
    }

    if (a + b + c == 1) {
        cout << 0 << '\n'; return;
    }

    int cur = 1, deg = 0, res = 0;
    for (int i = 0; i < a; ++i) {
        if (!cur) {
            swap(deg, cur);
            res++;
        }

        cur--;
        deg += 2;
    }

    for (int i = 0; i < b; ++i) {
        if (!cur) {
            swap(deg, cur);
            res++;
        }

        cur--;
        deg += 1;
    }

    cout << res + 1 << '\n';
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