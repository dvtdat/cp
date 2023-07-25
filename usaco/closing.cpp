//

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

vector<int> adj1[maxN];
bool visited[maxN];
bool closed[maxN];
int cntNodes;

void dfs(int u)
{
    if (visited[u] || closed[u]) return;

    cntNodes++;
    visited[u] = true;

    for (int v : adj1[u])
    {
        if (!visited[v]) dfs(v);
    }
}

void solve()
{
    int n, m, u, v; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    vector<int> closing(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> closing[i];
    }

    cntNodes = 0;
    dfs(1);

    if (cntNodes == n) cout << "YES\n"; else cout << "NO\n";

    for (int i = 0; i < n - 1; ++i)
    {
        cntNodes = 0;
        memset(visited, false, sizeof visited);

        closed[closing[i]] = true;
        dfs(closing[n - 1]);

        if (cntNodes == n - i - 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    //#ifndef ONLINE_JUDGE
        freopen("closing.in", "r", stdin);
        freopen("closing.out", "w", stdout);
    //#endif

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
