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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    
    vector<vector<ll>> f(n + 1, vector<ll>(2, infLL));

    f[0][0] = b * 1LL;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            f[i + 1][0] = min(f[i + 1][0], f[i][0] + a + b);
            f[i + 1][1] = min(f[i + 1][1], f[i][0] + 2 * (a + b));
            f[i + 1][1] = min(f[i + 1][1], f[i][1] + a + 2 * b);
            f[i + 1][0] = min(f[i + 1][0], f[i][1] + 2 * a + b);
        }
        else f[i + 1][1] = min(f[i + 1][1], f[i][1] + a + 2 * b);
    }

    cout << f[n][0] << '\n';
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

