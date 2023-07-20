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
int f[maxN][maxN];
int a[maxN];
bool visited[maxN];

void solve()
{
    memset(f, -1, sizeof f);
    memset(a, 0, sizeof a);
    memset(visited, false, sizeof visited);

    int n, m, c; cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    // PUSH DP

    f[0][1] = 0; // BASE CASE: make no moves
    for (int t = 0; t <= 1000; ++t)
    {
        for (int u = 1; u <= n; ++u)
        {
            if (f[t][u] == -1) continue;
            for (int v : adj[u])
            {
                f[t + 1][v] = max(f[t + 1][v], f[t][u] + a[v]);
            }
        }
    }

    int res = 0;
    for (int t = 0; t <= 1000; ++t)
    {
        res = max(res, f[t][1] - c * t * t);
    }

    cout << res << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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

