// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef pair<int, ii> iii;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

struct UnionFind
{
    vector<int> e;
    UnionFind(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    void join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    UnionFind uf(n + 1);
    vector<iii> edge;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        int w; cin >> u >> v >> w;
        edge.push_back(iii(w, ii(u, v)));
    }

    sort(edge.begin(), edge.end());

    int res = 0;
    for (iii e : edge)
    {
        if (uf.sameSet(e.second.first, e.second.second)) continue;
        res = max(res, e.first);
        uf.join(e.second.first, e.second.second);
    }

    cout << res << '\n';
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
    setIO("");
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

