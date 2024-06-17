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
    vector<vector<int>> a(n + 10, vector<int>(m + 10));
    vector<int> canSwapX(4, 0), canSwapY(4, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if (c == 'W') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i][0] != a[0][0]) canSwapX[0] = 1;
        if (a[i][0] != a[n - 1][0]) canSwapX[3] = 1;
        if (a[i][m - 1] != a[0][m - 1]) canSwapX[1] = 1;
        if (a[i][m - 1] != a[n - 1][m - 1]) canSwapX[2] = 1;
    }

    for (int j = 0; j < m; ++j) {
        if (a[0][j] != a[0][0]) canSwapY[0] = 1;
        if (a[0][j] != a[0][m - 1]) canSwapY[1] = 1;
        if (a[n - 1][j] != a[n - 1][0]) canSwapY[3] = 1;
        if (a[n - 1][j] != a[n - 1][m - 1]) canSwapY[2] = 1;
    }

    for (int i = 0; i < 4; ++i) {
        canSwapX[i] &= canSwapY[i];
    }

    if (a[0][0] == a[n - 1][m - 1] || canSwapX[0] || canSwapX[2]) {
        cout << "Yes\n";
        return;
    }

    if (a[n - 1][0] == a[0][m - 1] || canSwapX[1] || canSwapX[3]) {
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
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