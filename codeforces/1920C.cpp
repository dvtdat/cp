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
    vector<int> a(n);

    for (int &i : a) cin >> i;

    vector<int> div;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) div.push_back(i);
    }

    int res = 1;
    for (int jump : div) {

        int current = 0;
        for (int k = 0; k < jump; ++k)
        {
            int tmp = 0;
            for (int i = jump + k; i < n; i += jump) {
                tmp = __gcd(tmp, abs(a[i - jump] - a[i]));
            }
            current = __gcd(current, tmp);
        }
        res += (current != 1 ? 1 : 0);
    }

    cout << res << '\n';
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