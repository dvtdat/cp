// 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

/*
    - Reverse the problem: put every destinations as sources and put source as destination.
    - Traversing the graph, for every nodes, try to block the current best path going to that nodes.
*/

void dijkstra(vector<int> s, const int n, vector<int> &monster, const vector<vector<ii>> &adj, ll *d)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i <= n; ++i) d[i] = inf;
 
    for (int i = 0; i < s.size(); ++i)
    {
        pq.push(ii(0LL, s[i]));
    }
 
    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
 
        if (--monster[u] >= 0) continue;
        if (d[u] <= du) continue;
 
        d[u] = du;
 
        for (int i = 0; i < (int)adj[u].size(); ++i)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            pq.push(ii(d[u] + w, v));
        }
    }
}
 
void solve()
{
    int n, m, k; cin >> n >> m >> k;
 
    vector<int> exit(k);
    vector<int> monster(n + 1);
    vector<vector<ii>> adj(n + 1);
 
    for (int i = 0; i < k; ++i)
    {
        cin >> exit[i]; exit[i]--;
    }
    
    for (int i = 0; i < n; ++i) cin >> monster[i];
    
    for (int i = 0; i < k; ++i)
    {
        monster[exit[i]] = 0;
    }
 
    for (int i = 0; i < m; ++i)
    {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }
 
    ll d[n + 1];
    dijkstra(exit, n, monster, adj, d);
 
    cout << (d[0] == inf ? -1 : d[0]) << '\n';
    // for (int i = 0; i < n; ++i) cout << d[i] << ' '; cout << '\n';
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

