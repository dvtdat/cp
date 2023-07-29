// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 210;
const ll MOD = 998244353;
const double eps = 1e-12;

bool visited[maxN][maxN];
int dist[maxN][maxN];
int X, Y, k, m;

bool check(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs()
{
    queue<ii> q; q.push(ii(0, 0));
    dist[0][0] = 0;

    while (!q.empty())
    {
        int A = q.front().first;
        int B = q.front().second;
        int Xp = min(A, Y - B);
        int Yp = min(B, X - A);
        q.pop();

        if (visited[A][B]) continue;
        visited[A][B] = true;

        int dx[6], dy[6];
        dx[0] = A, dy[0] = 0;
        dx[1] = 0, dy[1] = B;
        dx[2] = X, dy[2] = B;
        dx[3] = A, dy[3] = Y;
        dx[4] = A - Xp, dy[4] = B + Xp;
        dx[5] = A + Yp, dy[5] = B - Yp;

        for (int k = 0; k < 6; ++k)
        {
            int vx = dx[k];
            int vy = dy[k];
            if (!check(vx, vy, maxN, maxN) || visited[vx][vy]) continue;
            dist[vx][vy] = dist[A][B] + 1;
            q.push(ii(vx, vy));
        }
    }
}

void solve()
{
    memset(dist, 0, sizeof dist);
    memset(visited, false, sizeof visited);

    cin >> X >> Y >> k >> m;
    bfs();

    int res = inf;
    for (int i = 0; i < maxN; ++i)
    {
        for (int j = 0; j < maxN; ++j)
        {
            if (dist[i][j] <= k && visited[i][j]) res = min(res, abs(i + j - m));
        }
    }

    cout << res << '\n';
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
    setIO("pails");
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

