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

int cnt = 0;

void solve() {
    string s; cin >> s;
    int k; cin >> k;
    
    vector<vector<int>> p(10, vector<int>());

    int len = s.length() - k;

    for (int i = 0; i < s.length(); ++i) {
        p[s[i] - '0'].push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        reverse(p[i].begin(), p[i].end());
    }
    vector<int> res;
    int tmp = 0;
    for (int i = 0; i < len; ++i) {
        for (int x = (i == 0); x < 10; ++x) {
            while (p[x].size() && p[x].back() < tmp) p[x].pop_back();
            if (p[x].size() && p[x].back() - tmp <= k) {
                k -= p[x].back() - tmp;
                tmp = p[x].back() + 1;
                res.push_back(x);
                break;
            }
        }
    }

    for (int i : res) cout << i; cout << "\n";
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

