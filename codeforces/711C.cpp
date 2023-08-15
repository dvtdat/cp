// best problem that I have done it all by myself so far

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const ll inf = 2e18 + 7;
const int maxN = 110;
const ll MOD = 998244353;
const double eps = 1e-12;

ll f[maxN][maxN][maxN];
ll c[maxN];
ll p[maxN][maxN];
int n, m, k;

// f[i][j][k]
// with i: i-th tree
//      j: that have the beauty j
//      k: colored with k

// dp algorithm:
// f[i][j][x] = min of
//                  min(f[i - 1][j - 1][k]) + p[i][x]   (with k != x)
//                  min(f[i - 1][j][x] + p[i][x])

// if the i-th tree have been colored, replace p[i][x] with 0
// check for special cases of x = 1 and x = i

// try to sketch out:
//      3 trees, 2 beauty: 1-1-2 or 1-2-2
//      3 trees, 3 beauty: 1-2-3
//      4 trees, 2 beauty: 1-1-1-2 or 1-1-2-2 or 1-2-2-2
//      4 trees, 3 beauty: 1-1-2-3 or 1-2-2-3 or 1-2-3-3
//      ...


void cal(int i, int j, int x, bool colored)
{
    int cost = colored ? 0 : p[i][x]; 
    if (j == 1)
    {
        f[i][j][x] = f[i - 1][j][x] + cost;
        return;
    }

    if (j == i) 
    {
        ll tmp = inf;
        for (int l = 1; l <= m; ++l)
            if (l != x) tmp = min(tmp, f[i - 1][j - 1][l]);
        f[i][j][x] = tmp + cost;
        return;
    }
    
    ll tmp = inf;
    for (int l = 1; l <= m; ++l)
        if (l != x) tmp = min(tmp, f[i - 1][j - 1][l]);

    f[i][j][x] = min(tmp + cost, f[i - 1][j][x] + cost);
}

void solve()
{
    memset(c, 0, sizeof c);
    memset(p, 0, sizeof p);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            for (int x = 1; x <= m; ++x) f[i][j][x] = inf;

    for (int i = 1; i <= n; ++i) cin >> c[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j) cin >> p[i][j];
    }

    if (c[1] == 0)
    {
        for (int j = 1; j <= m; ++j) f[1][1][j] = p[1][j];
    }
    else
    {
        f[1][1][c[1]] = 0;
    }

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= min(i, k); ++j)
        {
            if (c[i] == 0)
            {
                for (int x = 1; x <= m; ++x)
                {
                    cal(i, j, x, false);
                }
            }
            else
            {
                cal(i, j, c[i], true);
            }
        }
    }

    ll res = inf;
    for (int x = 1; x <= m; ++x) res = min(res, f[n][k][x]);
    cout << (res == inf ? -1 : res) << '\n';
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

