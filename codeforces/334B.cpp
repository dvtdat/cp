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
    vector<int> x(8), y(8);
    for (int i = 0; i < 8; ++i) cin >> x[i] >> y[i];

    vector<int> tmp = x;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    if (tmp.size() != 3) {
        cout << "ugly\n";
        return;
    }

    int mn = *min_element(x.begin(), x.end());
    int mx = *max_element(x.begin(), x.end());

    vector<int> a, b, c;

    for (int i = 0; i < 8; ++i) {
        if (x[i] == mn) a.push_back(y[i]);
        else if (x[i] == mx) c.push_back(y[i]);
        else b.push_back(y[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    if (a.size() != 3 || b.size() != 2 || c.size() != 3) {
        cout << "ugly\n";
        return;
    }

    if (a[0] != b[0] || a[0] != c[0] || b[0] != c[0] || a[1] != c[1] || a[2] != b[1] || a[2] != c[2] || c[2] != b[1]) {
        cout << "ugly\n";
        return;
    }
    cout << "respectable\n";
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
    setIO("");
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

