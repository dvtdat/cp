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

int g[500][500];
int a[500][500];
int n, k; 

int f(int i, int j, int m) {
    if (m == 1) return a[i][j];
    if (a[i / m][j / m] == 1) return 1;
    return f(i % m, j % m, m / n);
}

void solve() {
    memset(g, 0, sizeof g);
    memset(a, 0, sizeof a);
    cin >> n >> k;
    int m = 1;
    for (int i = 1; i <= k; ++i, m *= n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            if (c == '*') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i][j] = f(i, j, m / n);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j]) cout << '*';
            else cout << '.';
        }
        cout << '\n';
    }
}

void setIO(string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // #ifndef ONLINE_JUDGE
    //     freopen((name + ".inp").c_str(), "r", stdin);
    //     freopen((name + ".out").c_str(), "w", stdout);
    // #endif
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

