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
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    UnionFind uf(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> del(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> del[i];
        del[i]--;
    }

    reverse(del.begin(), del.end());
    vector<string> ans;
    vector<bool> connected(n, false);

    ans.push_back("YES\n");
    connected[del[0]] = true;
    int compCnt = 1;

    for (int i = 1; i < n; ++i)
    {
        compCnt++;
        connected[del[i]] = true;
        for (int v : adj[del[i]])
        {
            if (connected[v])
            {
                if (uf.join(v, del[i])) compCnt--;
            }
        }

        if (compCnt == 1) ans.push_back("YES\n");
        else ans.push_back("NO\n");
    }

    reverse(ans.begin(), ans.end());

    for (string s : ans) cout << s;
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
    setIO("closing");
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

