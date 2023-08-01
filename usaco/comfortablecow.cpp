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

bool visited[maxN][maxN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
queue<ii> q;
int n, res = 0;

void cal(int x, int y)
{
    if (!visited[x][y]) return;
    int tmp = 0;

    for (int k = 0; k < 4; ++k)
    {
        int vx = x + dx[k];
        int vy = y + dy[k];
        if (visited[vx][vy]) tmp++;
    }

    if (tmp != 3) return;

    for (int k = 0; k < 4; ++k)
    {
        int vx = x + dx[k];
        int vy = y + dy[k];
        if (!visited[vx][vy]) q.push(ii(vx, vy));
    } 
}

void bfs()
{
    while (!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();

        if (visited[ux][uy]) continue;
        
        visited[ux][uy] = true;
        res++;
        cal(ux, uy);

        for (int k = 0; k < 4; ++k)
        {
            int vx = ux + dx[k];
            int vy = uy + dy[k];
            cal(vx, vy);
        }
    }
}

void solve()
{
    memset(visited, false, sizeof visited);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        u += 1000, v += 1000;
        q.push(ii(u, v));
        bfs();
        cout << res - i - 1 << '\n';
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

