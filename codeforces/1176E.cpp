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

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> color(n + 1);
    vector<int> a, b;

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int s)
    {
        vector<int> visited(n + 1, false);
        queue<int> q;
        
        q.push(s);
        visited[s] = true;
        color[s] = 1;
        a.push_back(s);

        while (q.size())
        {
            int u = q.front(); q.pop();

            for (int v : adj[u])
            {
                if (visited[v]) continue;
                q.push(v);
                visited[v] = true;
                color[v] = !color[u];

                if (color[v]) a.push_back(v);
                else b.push_back(v);
            }
        }
    };

    bfs(0);

    if (a.size() < b.size())
    {
        cout << a.size() << '\n';
        for (int i : a) cout << i + 1 << ' '; cout << '\n';
    }
    else
    {
        cout << b.size() << '\n';
        for (int i : b) cout << i + 1 << ' '; cout << '\n';
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

