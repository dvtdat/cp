// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 300010;
const ll MOD = 998244353;
const double eps = 1e-12;

int visited[maxN];
vector<int> topo;
vector<int> adj[maxN];
int cnt[maxN][30];

void failed()
{
    cout << -1 << '\n';
    exit(0);
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == 1) failed();
        if (visited[v] == 0) dfs(v);
    }

    visited[u] = 2;
    topo.push_back(u);
}

void solve()
{
    memset(cnt, 0, sizeof cnt);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; ++i)
    {
        cnt[i][s[i] - 'a'] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0) dfs(i);
    }
    reverse(topo.begin(), topo.end());

    int res = 1;
    for (int u : topo)
    {
        for (int v : adj[u])
        {
            for (int i = 0; i < 26; ++i)
            {
                int factor = 0;
                if (s[v] - 'a' == i) factor = 1;
                cnt[v][i] = max(cnt[v][i], cnt[u][i] + factor);
                res = max(res, cnt[v][i]);
            }
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

