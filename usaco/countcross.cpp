// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 410;
const ll MOD = 998244353;
const double eps = 1e-12;

int c[maxN][maxN];
bool visited[maxN][maxN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int n, k, r;

bool check (int x, int y)
{
    return (0 <= x && x < n * 2 && 0 <= y && y < n * 2);
}

void bfs(int x, int y, int cnt)
{
    queue<ii> q; q.push(ii(x, y));

    while (!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();

        if (visited[ux][uy] || !check(ux, uy) || c[ux][uy]) continue;
        visited[ux][uy] = true;

        c[ux][uy] = cnt;

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
    memset(c, 0, sizeof c);
    memset(visited, false, sizeof visited);

    cin >> n >> k >> r;
    for (int i = 0; i < r; ++i)
    {
        int ux, uy, vx, vy;
        cin >> ux >> uy >> vx >> vy;
        ux--, uy--, vx--, vy--;

        if (uy > vy || ux > vx)
        {
            swap(ux, vx);
            swap(uy, vy);
        }

        if (ux == vx)
        {
            c[ux * 2][uy * 2 + 1] = -1;
            c[ux * 2 + 1][uy * 2 + 1] = -1;
        }
        else if (uy == vy)
        {
            c[ux * 2 + 1][uy * 2] = -1;
            c[ux * 2 + 1][uy * 2 + 1] = -1;
        }
    }

    vector<ii> cow(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> cow[i].first >> cow[i].second;
        cow[i].first--, cow[i].second--;
    }

    int cnt = 0;

    for (int i = 0; i < n * 2; ++i)
    {
        for (int j = 0; j < n * 2; ++j)
        {
            if (visited[i][j] || c[i][j] == -1) continue;
            bfs(i, j, ++cnt);
        }
    }

    vector<int> ans(cnt + 1, 0);
    for (ii x : cow)
    {
        ans[c[x.first * 2][x.second * 2]]++;
    }

    sort(ans.begin(), ans.end());

    ll res = 0LL;
    for (int i = 1; i <= cnt; ++i)
    {
        res += 1LL * ans[i] * ans[i - 1];
        ans[i] += ans[i - 1];
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
    setIO("countcross");
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

