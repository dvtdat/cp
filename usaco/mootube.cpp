// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ii> iii;

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
    bool join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

void solve()
{
    vector<iii> edge;
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        edge.push_back(iii(w, ii(u, v)));
    }

    sort(edge.rbegin(), edge.rend());

    vector<iii> query(m);
    for (int i = 0; i < m; ++i)
    {
        int k, v; cin >> k >> v;
        v--;
        query[i] = iii(-k, ii(i, v));
    }
    sort(query.begin(), query.end());

    UnionFind uf(n);
    vector<int> ans(m);
    int i = 0;
    for (iii q : query)
    {
        int k = -q.first;
        int v = q.second.second;
        int idx = q.second.first;

        while (edge[i].first >= k && i < edge.size())
        {
            uf.join(edge[i].second.first, edge[i].second.second);
            ++i;
        }

        ans[idx] = uf.size(v) - 1;
    }

    for (int i : ans) cout << i << '\n';
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
    setIO("mootube");
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

