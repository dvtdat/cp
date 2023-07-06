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

int get(int a, const vector<int> &par)
{
    while (a != par[a]) a = par[a];
    return a;
}

void unite(int &a, int &b, vector<int> &par)
{
    a = get(a, par);
    b = get(b, par);

    if (a == b) return;     // IMPORTANT

    if (par[a] == par[b]) par[a]++;
    if (par[a] > par[b]) par[b] = a;
    else par[a] = b;
};

struct Order
{
    int u, v;
    string order;
};

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    
    vector<int> par(n + 1);
    for (int i = 1; i <= n; ++i) par[i] = i;
    
    string order;
    int u, v;
    vector<ii> adj(m);
    vector<Order> op(q);

    for (int i = 0; i < m; ++i) cin >> adj[i].first >> adj[i].second;
    for (int i = 0; i < q; ++i) cin >> op[i].order >> op[i].u >> op[i].v;

    reverse(op.begin(), op.end());

    vector<string> res;

    for (int i = 0; i < q; ++i)
    {
        if (op[i].order == "cut")
        {
            unite(op[i].u, op[i].v, par);
        }
        else
        {
            res.push_back(get(op[i].u, par) == get(op[i].v, par) ? "YES" : "NO");
        }
    }

    reverse(res.begin(), res.end());
    for (string x : res) cout << x << '\n';
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

