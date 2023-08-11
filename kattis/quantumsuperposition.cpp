// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 2100;
const ll MOD = 998244353;
const double eps = 1e-12;

bool visited[maxN];
vector<int> adj[maxN];
vector<int> topo;
bool cnt[2][maxN][maxN];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v]) dfs(v);
    }
    topo.push_back(u);
}

void process(int n, int m, bool cnt[maxN][maxN])
{
    memset(visited, false, sizeof visited);
    for (int i = 0; i <= 2000; ++i) adj[i].clear();
    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());

    cnt[0][0] = true;
    for (int u : topo)
    {
        for (int v : adj[u])
        {
            for (int k = 0; k <= 2000; ++k)
            {
                cnt[v][k + 1] |= cnt[u][k];
            }
        }
    }
}

void solve()
{
    memset(cnt, false, sizeof cnt);
    int n1, n2, m1, m2; cin >> n1 >> n2 >> m1 >> m2;

    process(n1, m1, cnt[0]);
    process(n2, m2, cnt[1]);

    int q; cin >> q;
    while (q--)
    {
        int s; cin >> s;
        string ans = "No";
        for (int i = 0; i <= s; ++i)
        {
            if (cnt[0][n1 - 1][i] && cnt[1][n2 - 1][s - i]) ans = "Yes";
        }
        cout << ans << '\n';
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

