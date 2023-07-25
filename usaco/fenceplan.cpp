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

int x[maxN];
int y[maxN];
vector<int> adj1[maxN];

bool visited[maxN];

int bfs(int s)
{
    ii mx = ii(0, 0);
    ii mn = ii(inf, inf);

    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        mx.first = max(mx.first, x[u]);
        mx.second = max(mx.second, y[u]);
        mn.first = min(mn.first, x[u]);
        mn.second = min(mn.second, y[u]);

        // cout << u << ' ' << x[u] << ' ' << y[u] << ' ' << mx.first << ' ' << mx.second << ' ' << mn.first << ' ' << mn.second << '\n';

        for (int v : adj1[u])
        {
            if (!visited[v]) q.push(v);
        }
    }

    return 2 * abs(mx.first - mn.first) + 2 * abs(mx.second - mn.second);
}

void solve()
{
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(visited, false, sizeof visited);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    int res = inf;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i]) res = min(res, bfs(i));
    }

    cout << res << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
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

