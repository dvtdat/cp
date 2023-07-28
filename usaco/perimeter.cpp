// 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 1010;
const ll MOD = 998244353;
const double eps = 1e-12;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool visited[maxN][maxN];
char c[maxN][maxN];

bool check (int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

ii bfs(int x, int y, int n, int m)
{
    ll area = 0;
    ll peri = 0;

    queue<ii> q; q.push(ii(x, y));

    while (!q.empty())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();

        if (visited[ux][uy] || !check(ux, uy, n, n) || c[ux][uy] != '#') continue;
        visited[ux][uy] = true;

        area += 1;
        peri += 4;

        for (int k = 0; k < 4; ++k)
        {
            q.push(ii(ux + dx[k], uy + dy[k]));
            if (c[ux + dx[k]][uy + dy[k]] == '#') peri--;
        }
    }

    return ii(-area, peri);
}

void solve()
{
    memset(visited, false, sizeof visited);
    memset(c, '.', sizeof c);

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) cin >> c[i][j];
    }

    vector<ii> res;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visited[i][j]) continue;
            res.push_back(bfs(i, j, n, n));
        }
    }

    sort(res.begin(), res.end());

    cout << -res[0].first << ' ' << res[0].second << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
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

