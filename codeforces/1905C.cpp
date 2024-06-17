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
    string s; cin >> s;
    
    vector<vector<int>> idx(30, vector<int>(0));

    for (int i = 0; i < n; ++i) {
        int x = s[i] - 'a';
        idx[x].push_back(i);
    }

    reverse(idx.begin(), idx.end());

    int cur = 0;
    bool flag = false;
    int lastSz = 0;
    vector<int> vt;
    string str = "";

    for (vector<int> v : idx) {
        int lower = lower_bound(v.begin(), v.end(), cur) - v.begin();
        if (lower >= v.size()) continue;
        for (int i = lower; i < v.size(); ++i) vt.push_back(v[i]), str.push_back(s[v[i]]);
        cur = vt.back();

        if (!flag) lastSz = v.size();
        flag = true;
    }

    sort(vt.begin(), vt.end());
    sort(str.begin(), str.end());

    string b = s;
    for (int i = 0; i < vt.size(); ++i) {
        b[vt[i]] = str[i];
    }

    sort(s.begin(), s.end());
    
    if (b == s) {
        cout << vt.size() - lastSz << '\n';
    } else {
        cout << -1 << '\n';
    }
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

