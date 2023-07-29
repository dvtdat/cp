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

int c[maxN][maxN];
bool visited[maxN][maxN];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

bool check (int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs(int x, int y, int n, int m, int lim)
{
    queue<ii> q; q.push(ii(x, y));

    while (!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();

        if (visited[ux][uy] || !check(ux, uy, n, m)) continue;
        visited[ux][uy] = true;

        for (int k = 0; k < 4; ++k)
        {
            int vx = ux + dx[k];
            int vy = uy + dy[k];
            if (abs(c[vx][vy] - c[ux][uy]) > lim || !check(vx, vy, n, m)) continue;
            q.push(ii(ux + dx[k], uy + dy[k]));
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<ii> waypoint;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int u; cin >> u;
            if (!u) continue;
            waypoint.push_back(ii(i, j));
        }
    }

    if (waypoint.empty() || waypoint.size() == 1)
    {
        cout << 0 << '\n';
        return;
    }

    bool flag = true;
    bfs(waypoint[0].first, waypoint[0].second, n, m, 0);
    for (ii k : waypoint)
    {
        if (!visited[k.first][k.second] && c[k.first][k.second]) flag = false;
    }

    if (flag)
    {
        cout << 0 << '\n';
        return;
    }

    int l = 0, r = inf, mid;
    while (r - l > 1)
    {
        memset(visited, false, sizeof visited);
        mid = (l + r) / 2;
        flag = true;

        bfs(waypoint[0].first, waypoint[0].second, n, m, mid);
        
        for (ii k : waypoint)
        {
            if (!visited[k.first][k.second] && c[k.first][k.second]) flag = false;
        }

        if (flag) r = mid;
        else l = mid;
    }

    cout << r << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("ccski.in", "r", stdin);
        freopen("ccski.out", "w", stdout);
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

