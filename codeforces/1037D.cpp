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
    int n; cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> v(n + 1), vi(n + 1);
    vector<int> res;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        vi[v[i]] = i + 1;
    }

    auto bfs = [&](int s)
    {
        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(s);
        visited[s] = true;

        while (q.size())
        {
            int u = q.front(); q.pop();
            res.push_back(u);

            for (int v : adj[u])
            {
                if (visited[v]) continue;
                q.push(v);
                visited[v] = true;
            }
        }
    };

    auto cmp = [&](int a, int b)
    {
        return (vi[a] < vi[b]);
    };

    for (int i = 1; i <= n; ++i)
    {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }

    bfs(1);

    for (int i = 0; i < n; ++i)
    {
        if (v[i] == res[i]) continue;
        cout << "no\n"; return;
    }
    cout << "yes\n";
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

