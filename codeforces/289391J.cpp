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
    vector<int> len;
    vector<int> sz;
    UnionFind(int n) : e(n, -1), len(n, -1), sz(n, 1) {}

    ii find(int x)
    {
        if (e[x] < 0) return ii(x, 0);
        ii tmp = find(e[x]);
        e[x] = tmp.first;
        len[x] = (len[x] + tmp.second) % 2;
        return ii(e[x], len[x]);
    }
    
    void join(int a, int b)
    {
        ii A = find(a);
        ii B = find(b);

        if (sz[A.first] > sz[B.first]) swap(A, B);

        e[A.first] = B.first;
        len[A.first] = (A.second + B.second + 1) % 2;
        sz[B.first] += sz[A.first];
    }
};

void solve()
{
    int n, m; cin >> n >> m;

    UnionFind uf(n + 1);
    
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        ii U = uf.find(u);
        ii V = uf.find(v);

        // cout << U.first << ' ' << U.second << ' ';
        // cout << V.first << ' ' << V.second << '\n';

        if (U.first != V.first)
        {
            uf.join(u, v);
        }
        else if (U.second == V.second)
        {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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

