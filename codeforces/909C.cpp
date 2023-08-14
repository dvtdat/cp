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
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> f(n + 5, vector<int>(n + 5, 0));
    vector<bool> state(n);

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        state[i] = (c == 's' ? 1 : 0);
    }

    // PUSH DP
    f[0][0] = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (!state[i])
        {
            f[i + 1][0] = 0;
            for (int j = 1; j < n; ++j) f[i + 1][j] = f[i][j - 1];
        }
        else
        {
            int tmp = 0;
            for (int j = n - 1; j >= 0; --j)
            {
                tmp = (tmp % MOD + f[i][j] % MOD) % MOD;
                f[i + 1][j] = tmp;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = (res % MOD + f[n - 1][i] % MOD) % MOD;
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

