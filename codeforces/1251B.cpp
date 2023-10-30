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

void solve()
{
    int n; cin >> n;
    bool haveOdd = false;
    int need = 0;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (s.length() & 1) {
            haveOdd = true;
            continue;
        }

        int sum = 0;
        for (char c : s) sum += (int)(c - '0');
        if (sum & 1) need++;
    }

    need %= 2;

    if (!need) {
        cout << n << '\n'; return;
    }

    if (haveOdd) cout << n << '\n';
    else cout << n - 1 << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
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

