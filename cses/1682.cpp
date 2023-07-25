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

bool visited1[maxN];
bool visited2[maxN];
vector<int> adj1[maxN];
vector<int> adj2[maxN];
int n, m;

void bfs(int s, vector<int> *adj, bool* visited)
{
    for (int i = 0; i < maxN; ++i) visited[i] = false;
    queue<int> q; q.push(s);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v]) q.push(v);
        }
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    bfs(0, adj1, visited1);
    bfs(0, adj2, visited2);

    for (int i = 0; i < n; ++i)
    {
        if (!visited1[i])
        {
            cout << "NO\n";
            cout << 1 << ' ' << i + 1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited2[i])
        {
            cout << "NO\n";
            cout << i + 1 << ' ' << 1 << '\n';
            return;
        }
    }

    cout << "YES\n";
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

