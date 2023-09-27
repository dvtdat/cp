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
    string s; cin >> s;
    int n = s.length();
    vector<int> p(n + 1, 0);

    for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + (s[i - 1] == '0' ? 1 : 0);

    int res = inf;

    for (int i = 1; i <= n; ++i)
    {
        res = min(res, (i - p[i]) + (p[n] - p[i]));
    }

    for (int i = 1; i <= n; ++i)
    {
        res = min(res, p[i] + ((n - i) - (p[n] - p[i])));
    }

    cout << res << '\n';
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

