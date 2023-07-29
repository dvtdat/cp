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

bool c[maxN][maxN];
bool visited[maxN][maxN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int mnX = 2001, mnY = 2001, mxX = 2001, mxY = 2001;

bool check (int x, int y)
{
    return (mnX <= x && x <= mxX && mnY <= y && y <= mxY);
}

void bfs(int x, int y)
{
    queue<ii> q; q.push(ii(x, y));

    while (!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();

        if (visited[ux][uy] || !check(ux, uy) || c[ux][uy]) continue;
        visited[ux][uy] = true;

        for (int k = 0; k < 4; ++k)
        {
            int vx = ux + dx[k];
            int vy = uy + dy[k];
            q.push(ii(vx, vy));
        }
    }
}

void solve()
{
    memset(c, false, sizeof c);
    memset(visited, false, sizeof visited);

    int n; cin >> n;
    string s; cin >> s;

    int x = 2001, y = 2001;

    for (int i = 0; i < n; ++i)
    {
        int a = 0, b = 0;
        if (s[i] == 'N') a = 1, b = 0;
        if (s[i] == 'S') a = -1, b = 0;
        if (s[i] == 'E') a = 0, b = 1;
        if (s[i] == 'W') a = 0, b = -1;

        c[x + a][y + b] = true;
        c[x + a * 2][y + b * 2] = true;

        x += a * 2;
        y += b * 2;

        mnX = min(x, mnX);
        mnY = min(y, mnY);
        mxX = max(x, mxX);
        mxY = max(y, mxY);
    }

    mnX--, mnY--;
    mxX++, mxY++;

    int res = 0;
    for (int i = mnX; i <= mxX; ++i)
    {
        for (int j = mnY; j <= mxY; ++j)
        {
            if (visited[i][j] || c[i][j]) continue;
            bfs(i, j);
            res++;
        }
    }

    cout << res - 1 << '\n';
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

