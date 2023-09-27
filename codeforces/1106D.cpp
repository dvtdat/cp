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

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> res;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int s)
    {
        priority_queue<int> pq;
        vector<bool> visited(n, 0);
        pq.push(-s);
        visited[s] = true;

        while (pq.size())
        {
            int u = pq.top(); pq.pop();
            u = -u;

            res.push_back(u);

            for (int v : adj[u])
            {
                if (visited[v]) continue;
                visited[v] = true;
                pq.push(-v);
            }
        }
    };

    bfs(0);
    for (int v : res) cout << v + 1 << ' '; cout << '\n';
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

