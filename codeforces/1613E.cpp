// lol solved 2k graph

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
    int n, m; cin >> n >> m;

    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));

    for (int i = 0; i <= m + 1; ++i) a[0][i] = a[n + 1][i] = 1;
    for (int i = 0; i <= n + 1; ++i) a[i][0] = a[i][m + 1] = 1;

    int sx = 0, sy = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char c; cin >> c;
            if (c == '#') a[i][j] = 1;
            if (c == 'L') a[i][j] = 2, sx = i, sy = j;
        }
    }

    auto bfs = [&]()
    {
        queue<ii> q;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

        q.push(ii(sx, sy));

        auto cal = [&](int x, int y)
        {
            int tmp = 0;
            if (a[x + 1][y]) tmp++;
            if (a[x - 1][y]) tmp++;
            if (a[x][y + 1]) tmp++;
            if (a[x][y - 1]) tmp++;

            return (bool)(tmp >= 3 ? true : false);
        };

        while (q.size())
        {
            int ux = q.front().first;
            int uy = q.front().second;
            q.pop();

            for (int k = 0; k < 4; ++k)
            {
                int vx = ux + dx[k];
                int vy = uy + dy[k];

                if (a[vx][vy] != 0) continue;
                if (cal(vx, vy))
                {
                    a[vx][vy] = 2;
                    q.push(ii(vx, vy));
                }
            }
        }
    };

    bfs();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 0) cout << ".";
            else if (a[i][j] == 1) cout << "#";
            else
            {
                if (i == sx && j == sy) cout << "L";
                else cout << "+";
            }
        }
        cout << '\n';
    }
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

