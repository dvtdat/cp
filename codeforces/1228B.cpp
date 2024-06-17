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
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

const int MX = 1e3 + 10;

int a[MX][MX];

void solve() {
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) a[i][j] = 0;
    }

    int n, m; cin >> n >> m;
    vector<int> r(n), c(m);
    for (int &x : r) cin >> x;
    for (int &x : c) cin >> x;

    for (int i = 0; i < n; ++i) {
        int x = r[i];
        if (x == 0) {
            a[i][0] = 2;
            continue;
        }

        for (int j = 0; j < x; ++j) {
           a[i][j] = 1;     
        }

        a[i][x] = 4;
    }

    for (int j = 0; j < m; ++j) {
        int x = c[j];
        if (x == 0) {
            a[0][j] = 2;
            continue;
        }

        for (int i = 0; i < x; ++i) {
            if (a[i][j] == 2) {
                cout << 0 << '\n'; return;
            } else a[i][j] = 1;
        }

        a[x][j] = 4;
    }

    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (a[i][j] == 1) j++;
        if (j != r[i]) {
            cout << 0 << '\n'; return;
        }
    }

    for (int j = 0; j < m; ++j) {
        int i = 0;
        while (a[i][j] == 1) i++;
        if (i != c[j]) {
            cout << 0 << '\n'; return;
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // cout << a[i][j];
            if (a[i][j] == 0) ans *= 2;
            ans %= MOD;
        }
        // cout << '\n';
    }

    cout << ans << '\n'; 
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