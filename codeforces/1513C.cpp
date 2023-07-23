// WRONG ANSWER

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
    string s;
    int k; 
    cin >> s >> k;

    vector<vector<ll>> f(10, vector<ll>(k + 5, 0LL));

    for (int i = 0; i < s.size(); ++i)
    {
        f[s[i] - '0'][0]++;
    }

    for (int i = 1; i <= k; ++i)
    {
        f[0][i] = f[9][i - 1];
        f[1][i] = f[9][i - 1] + f[0][i - 1];
        f[1][i] %= MOD;

        for (int j = 2; j <= 9; ++j) f[j][i] = f[j - 1][i - 1];
    }

    ll res = 0;
    for (int i = 0; i <= 9; ++i)
    {
        res = (res + f[i][k]) % MOD;
    }

    cout << res << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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

