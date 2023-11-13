// 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve() {
    ll n; cin >> n;
    stack<ii> s;
    for (int i = 0; i < n; ++i) {
        string order; cin >> order;
        if (order == "add") {
            s.push(ii(1, 1));
        }
        if (order == "for") {
            int k; cin >> k;
            s.push(ii(0, k));
        }
        if (order == "end") {
            ll tmp = 0;
            while (s.size() && s.top().first != 0) {
                tmp += s.top().second;
                s.pop();
            }

            if (s.empty() && s.top().first != 0) {
                cout << "OVERFLOW!!!\n";
                return;
            }

            ll k = s.top().second; s.pop();
            s.push(ii(1, min(1ll << 32, k * tmp)));
        }
    }

    ll total = 0;
    while (s.size()) {
        if (s.top().first == 0) {
            cout << "OVERFLOW!!!\n";
            return;
        }
        total += s.top().second; s.pop();
    }

    if (total >= 1ll << 32) cout << "OVERFLOW!!!";
    else cout << total;
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

