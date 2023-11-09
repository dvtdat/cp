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
    vector<int> a(n + 1, 0), p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }

    if (n == 1) {
        cout << 0 << '\n'; return;
    }

    int res = 0;
    for (int i = 1; i < n; ++i) {
        int j = i + 1;
        int tmp = 0;
        int cnt = 1;

        while (j <= n) {
            if (tmp + a[j] < p[i]) {
                tmp += a[j];
            }
            else if (tmp + a[j] > p[i]) {
                cnt = 1;
                break;
            }
            else if (tmp + a[j] == p[i]){
                cnt++;
                tmp = 0;
            }
            j++;
        }

        if (tmp != 0) cnt = 1;

        res = max(res, cnt);
    }

    cout << n - res << '\n';
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

