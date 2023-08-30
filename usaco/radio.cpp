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

ii check(char c)
{
    if (c == 'N') return ii(0, 1);
    if (c == 'S') return ii(0, -1);
    if (c == 'E') return ii(1, 0);
    if (c == 'W') return ii(-1, 0);
}

int calc(ii a, ii b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve()
{
    int n, m; cin >> n >> m;

    vector<ii> vA(n + 1), vB(m + 1);
    cin >> vA[0].first >> vA[0].second;
    cin >> vB[0].first >> vB[0].second;

    string sA, sB; cin >> sA >> sB;

    for (int i = 0; i < n; ++i)
    {
        ii d = check(sA[i]);
        vA[i + 1] = ii(vA[i].first + d.first, vA[i].second + d.second);
    }

    for (int i = 0; i < m; ++i)
    {
        ii d = check(sB[i]);
        vB[i + 1] = ii(vB[i].first + d.first, vB[i].second + d.second);
    }

    vector<vector<int>> f(n + 1, vector<int>(m + 1, inf));
    f[0][0] = 0;

    // PUSH DP
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            f[i + 1][j] = min(f[i + 1][j], f[i][j] + calc(vA[i + 1], vB[j]));
            f[i][j + 1] = min(f[i][j + 1], f[i][j] + calc(vA[i], vB[j + 1]));
            f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + calc(vA[i + 1], vB[j + 1]));

        }
    }

    cout << f[n][m] << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("radio");
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

