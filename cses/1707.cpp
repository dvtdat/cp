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

vector<int> adj[maxN];

int bfs(int s)
{
    vector<int> d(maxN, -1);
    vector<int> visited(maxN, false);
    int res = inf;

    queue<int> q;
    q.push(s);
    d[s] = 0;
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
            else if (d[u] <= d[v])
            {
                res = min(res, d[u] + d[v] + 1);
            }
        }
    }

    return res;
}

void solve()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = inf;

    for (int i = 0; i < n; ++i)
    {
        res = min(res, bfs(i));
    }

    cout << (res == inf ? -1 : res) << '\n';
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

