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

int f[maxN][30][5];
int a[maxN];

void solve()
{
    memset(f, 0, sizeof f);
    memset(a, 0, sizeof a);

    int n, k; cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        char c; cin >> c;
        if (c == 'P') a[i] = 0;
        else if (c == 'S') a[i] = 1;
        else a[i] = 2;
    }

    // PULL DP

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k + 1; ++j)
        {
            int add;
            add = (a[i] == 0 ? 1 : 0); // is Paper
            f[i][j][0] = max(f[i - 1][j][0], max(f[i - 1][j - 1][1], f[i - 1][j - 1][2])) + add;

            add = (a[i] == 1 ? 1 : 0); // is Scissor
            f[i][j][1] = max(f[i - 1][j][1], max(f[i - 1][j - 1][0], f[i - 1][j - 1][2])) + add;

            add = (a[i] == 2 ? 1 : 0); // is Hoof
            f[i][j][2] = max(f[i - 1][j][2], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1])) + add;
        }
    }

    int res = 0;
    for (int j = 1; j <= k + 1; ++j)
    {
        res = max(res, max(f[n][j][0], max(f[n][j][1], f[n][j][2])));
    }

    cout << res << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
        freopen("hps.in", "r", stdin);
        freopen("hps.out", "w", stdout);
    // #endif
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

