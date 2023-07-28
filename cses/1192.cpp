// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 1010;
const ll MOD = 998244353;
const double eps = 1e-12;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int visited[maxN][maxN];
char c[maxN][maxN];

bool check(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs(int x, int y, int n, int m)
{
    queue<ii> q;
    q.push(ii(x, y));

    while (!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();

        if (visited[ux][uy] || !check(ux, uy, n, m) || c[ux][uy] == '#') continue;
        visited[ux][uy] = true;

        for (int k = 0; k < 4; ++k) q.push(ii(ux + dx[k], uy + dy[k]));
    }
}

void solve()
{
    memset(visited, false, sizeof visited);
    memset(c, '.', sizeof c);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> c[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j] || c[i][j] == '#') continue;
            bfs(i, j, n, m);
            res++;
        }
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

