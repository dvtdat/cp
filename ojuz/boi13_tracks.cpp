// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 4010;
const ll MOD = 998244353;
const double eps = 1e-12;

int d[maxN][maxN];
int a[maxN][maxN];
bool visited[maxN][maxN];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int res = 0;

bool check(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs(int n, int m)
{
    deque<ii> q; q.push_front(ii(0, 0));

    while (!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop_front();

        if (visited[ux][uy]) continue;
        visited[ux][uy] = true;

        res = max(res, d[ux][uy]);

        for (int k = 0; k < 4; ++k)
        {
            int vx = ux + dx[k];
            int vy = uy + dy[k];
            if (!check(vx, vy, n, m) || visited[vx][vy] || a[vx][vy] == 0) continue;

            if (a[vx][vy] == a[ux][uy])
            {
                d[vx][vy] = d[ux][uy];
                q.push_front(ii(vx, vy));
            }
            else 
            {
                d[vx][vy] = d[ux][uy] + 1;
                q.push_back(ii(vx, vy));
            }
        }
    }
}

void solve()
{
    memset(visited, false, sizeof visited);
    memset(d, 0, sizeof d);
    memset(a, 0, sizeof a);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            if (c == 'F') a[i][j] = 1;
            else if (c == 'R') a[i][j] = 2;
            else a[i][j] = 0;
        }
    }

    bfs(n, m);

    cout << res + 1 << '\n';
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
    setIO("");
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

