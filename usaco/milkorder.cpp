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

vector<int> mat[maxN];
vector<int> topo;

bool check(int n, int x)
{
    topo.clear();
    vector<int> visited(n, 0);
    vector<priority_queue<int>> adj(n, priority_queue<int>());

    for (int i = 1; i <= x; ++i)
    {
        for (int j = 0; j < mat[i].size() - 1; ++j)
        {
            adj[mat[i][j]].push(mat[i][j + 1]);
        }
    }

    function<bool(int)> dfs = [&](int u) -> bool {
        visited[u] = 1;
        bool flag = true;
        while (!adj[u].empty())
        {
            int v = adj[u].top(); adj[u].pop();
            if (visited[v] == 1) return false;
            if (!visited[v])
            {
                flag = dfs(v);
                if (!flag) return false;
            }
        }

        visited[u] = 2;
        topo.push_back(u);

        return true;
    };

    for (int i = n - 1; i >= 0; --i)
    {
        if (!visited[i])
        {
            if (!dfs(i)) return false;
        }
    }
    reverse(topo.begin(), topo.end());

    return true;
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int k; cin >> k;
        while (k--)
        {
            int u; cin >> u; u--;
            mat[i].push_back(u);
        }
    }

    int l = 1, r = m;
    int cnt = 0;

    while (r - l > 0 && cnt++ < 100) // i put guard here for some reason idk
    {
        int mid = l + (r - l) / 2;
        if (check(n, mid)) l = mid;
        else r = mid;
    }
    
	for (int i = 0; i < n; i++) { cout << topo[i] + 1 << (i != n - 1 ? " " : ""); }
    cout << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("milkorder");
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

