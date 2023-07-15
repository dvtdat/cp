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
 
int r[maxN];

// path compression
int get(int a, vector<int> &par)
{
    if (a != par[a])
    {
        int root = get(par[a], par);
        r[a] += r[par[a]];
        par[a] = root;
    }

    return par[a];
}
 
int getRank(int a, vector<int> &par)
{
    get(a, par);
    return -r[a];
}
 
void unite(int a, int b, vector<int> &par)
{
    int rootA = get(a, par);
    int rootB = get(b, par);
 
    par[rootB] = rootA;
    r[rootB] = r[a] - r[b] - 1;
}
 
void solve()
{
    int n, q; cin >> n >> q;
 
    vector<int> par(n + 1);
    for (int i = 1; i <= n; ++i) par[i] = i, r[i] = 0;

    while (q--)
    {
        int order, a, b;
        cin >> order;
        if (order == 1)
        {
            cin >> a >> b;
            unite(b, a, par);
        }
        else
        {
            cin >> a;
            cout << getRank(a, par) << '\n';
        }
    }

    // for (int i = 1; i <= n; ++i) cout << getRank(i, par) << ' '; cout << '\n';
    // for (int i = 1; i <= n; ++i) cout << par[i] << ' ';
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