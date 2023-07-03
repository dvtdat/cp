// lmao

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

struct Edge
{
    int u, v, w;
};

bool cmp(const Edge &x, Edge &y)
{
    return x.w < y.w;
}

void solve()
{
    int n = 4, m = 4;
    vector<Edge> adj;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w; cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }

    sort(adj.begin(), adj.end(), cmp);

    cout << '\n';
    for (int i = 0; i < m; ++i)
    {
        cout << adj[i].u << ' ' << adj[i].v << ' ' << adj[i].w << '\n';
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
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

