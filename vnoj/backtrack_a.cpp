// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 100;
const ll MOD = 998244353;
const double eps = 1e-12;

vector<int> subset;
vector<int> res;
int n, k;
int mn = inf;
int cur = 0;

int g[maxN][maxN];

void get(int pos, int last) {
    for (int i = 2; i <= n; ++i) {
        if (subset.size() && find(subset.begin(), subset.end(), i) != subset.end()) continue;
        
        subset.push_back(i);
        cur += g[last][i];

        if (subset.size() == k) {
            if (cur + g[i][1] < mn) {
                mn = cur + g[i][1];
                res = subset;
            }
        } else get(pos + 1, i);
        
        subset.pop_back();
        cur -= g[last][i];   
    }
}

void solve() {
    cin >> n >> k;
    k--;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> g[i][j];
    }

    get(1, 1);

    cout << mn << '\n' << 1 << ' ';
    for (int i : res) cout << i << ' '; cout << '\n';
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

