// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 100010;
const ll MOD = 998244353;
const double eps = 1e-12;

bool toggle = false;
int cnt[maxN];
bool visited[maxN];
vector<int> adj[maxN];
map<ii, int> edge;

void dfs(int s)
{
    visited[s] = true;
    for (int i = 0; i < adj[s].size(); ++i)
    {
        if (!visited[adj[s][i]])
        {
            int u = s, v = adj[s][i];
            if (u > v) swap(u, v);
            edge[ii(s, adj[s][i])] = toggle;
            edge[ii(adj[s][i], s)] = toggle;
            toggle = !toggle;
            dfs(adj[s][i]);
        }
    }
}

void solve()
{
    int n; cin >> n;
    
    vector<ii> save;

    memset(cnt, 0, sizeof cnt);
    memset(visited, false, sizeof visited);
    for (int i = 0; i <= n; ++i) adj[i].clear();
    edge.clear();

    int u, v;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
        save.push_back(ii(u, v));
    }

    int start = 0, tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i] != 1 && cnt[i] != 2)
        {
            cout << -1 << '\n';
            return;
        }

        if (cnt[i] == 1) start = i, tmp++;
    }

    if (tmp != 2)
    {
        cout << -1 << '\n';
        return;
    }

    dfs(start);

    for (ii i : save)
    {
        cout << edge[i] + 2 << ' ';
    }

    cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
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

