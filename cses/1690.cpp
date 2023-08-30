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
const ll MOD = (int)1e9 + 7;
const double eps = 1e-12;

void solve()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
    }

    vector<vector<ll>> f(1 << n, vector<ll>(n, 0));
    f[1][0] = 1; // base case: one way to start at the city 1

    for (int i = 2; i < (1 << n); ++i)
    {
        if ((i & (1 << 0)) == 0) continue;
        // only check subsets that contain city 1
        
        if ((i & (1 << (n - 1))) && i != ((1 << n) - 1)) continue;
        // if the subset is full, only check those contain city n

        for (int u = 0; u < n; ++u)
        {
            if ((i & (1 << u)) == 0) continue;

            int rest = i - (1 << u);
            for (int v : adj[u])
            {
                if ((i & (1 << v)) == 0) continue;
                (f[i][u] += f[rest][v]) %= MOD;
            }
        }
    }

    cout << f[(1 << n) - 1][n - 1] << '\n';
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

