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

int f[maxN][8];
int mask[maxN];
int cost[maxN];

void solve()
{
    memset(mask, 0, sizeof mask);
    memset(cost, 0, sizeof cost);

    int n; cin >> n;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < 8; ++j) f[i][j] = inf;
    }

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> cost[i] >> s;

        for (int j = 0; j < s.length(); ++j)
        {
            if (s[j] == 'A') mask[i] += (1 << 2);
            else if (s[j] == 'B') mask[i] += (1 << 1);
            else if (s[j] == 'C') mask[i] += (1 << 0);
        }
    }

    // DP BITMASK
    // PUSH DP

    f[0][0] = 0; // BASE CASE

    for (int i = 0; i < n; ++i)
    {
        for (int m = 0; m < 8; ++m)
        {
            f[i + 1][m] = min(f[i + 1][m], f[i][m]);
            f[i + 1][m | mask[i]] = min(f[i + 1][m | mask[i]], f[i][m] + cost[i]);
        }
    }
    
    cout << (f[n][7] == inf ? -1 : f[n][7]) << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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

