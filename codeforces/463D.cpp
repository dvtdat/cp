// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 1010;
const ll MOD = 998244353;
const double eps = 1e-12;

vector<int> adj[maxN];
int visited[maxN];
vector<int> topo;

void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u]) 
    {
        if (!visited[v]) dfs(v);
    }
    topo.push_back(u);
}

void solve()
{
    memset(visited, 0, sizeof visited);
    int n, k; cin >> n >> k;

    vector<vector<int>> idx(k + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int u;
            cin >> u;
            idx[i][u] = j;
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) continue;
            bool flag = true;
            for (int l = 0; l < k; ++l)
            {
                if (idx[l][i] > idx[l][j]) flag = false;
            }
            if (flag) adj[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i]) dfs(i);
    }

    vector<int> f(n + 1, 1);
    reverse(topo.begin(), topo.end());
    for (int u : topo)
    {
        for (int v : adj[u]) f[v] = max(f[v], f[u] + 1);
    }

    cout << *max_element(f.begin(), f.end());
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

