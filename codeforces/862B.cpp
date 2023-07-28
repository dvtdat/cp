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

vector<int> adj[maxN];
bool visited[maxN];
int d[maxN];

bool bfs(int s)
{
    queue<int> q; q.push(s);
    d[s] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (int v : adj[u])
        {
            if (visited[v]) continue;
            d[v] = (d[u] + 1) % 2;
            q.push(v);
        }

        for (int v : adj[u])
        {
            if (d[v] == d[u]) return false;
        }
    }
    return true;
}

void solve()
{
    memset(d, -1, sizeof d);
    memset(visited, false, sizeof visited);
    
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i]) continue;
        bfs(i);
    }

    ll cnt = 0;
    for (int i = 0; i < n; ++i) cnt += 1LL * d[i];

    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (d[i] == 0) res += 1LL * cnt - adj[i].size();
    }

    cout << res << '\n';
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

