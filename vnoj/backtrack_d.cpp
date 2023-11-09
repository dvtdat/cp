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

unsigned long long mask[50];
unsigned long long res = 0;
int n;

void f(int i, unsigned long long curr) {
    if (curr == (1 << 26) - 1) res++;
    if (i >= n) return;
    f(i + 1, curr | mask[i]);
    f(i + 1, curr);
}

void solve() {
    cin >> n;
    memset(mask, 0, sizeof mask);

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (char c : s) {
            mask[i] |= (1 << (c - 'a'));
        }
    }

    f(0, 0);
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

