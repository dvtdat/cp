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

int get(int a, vector<int> &par)
{
    return par[a] = (par[a] == a ? a : get(par[a], par));
}

void unite(int a, int b, vector<int> &par, vector<int> &rank)
{
    a = get(a, par);
    b = get(b, par);

    if (rank[a] == rank[b]) rank[a]++;

    if (rank[a] > rank[b]) par[b] = a;
    else par[a] = b;
}

void uniteRange(int a, int b, vector<int> &par, vector<int> &rank, set<int> &unconnected)
{
    int pos = a;
    while ((pos = *unconnected.lower_bound(pos)) < b)
    {
        unconnected.erase(pos);
        unite(pos, pos + 1, par, rank);
    }
}

void solve()
{
    int n, q; cin >> n >> q;

    vector<int> par(n + 1);
    vector<int> rank(n + 1, 1);
    set<int> unconnected;
    set<int>::iterator it = unconnected.end();

    for (int i = 0; i <= n; ++i) par[i] = i;
    for (int i = 0; i <= n; ++i) it = unconnected.insert(it, i);

    while (q--)
    {
        int w, u, v; cin >> w >> u >> v;

        if (w == 1) unite(u, v, par, rank);
        if (w == 2) uniteRange(u, v, par, rank, unconnected);
        if (w == 3)
        {
            cout << (get(u, par) == get(v, par) ? "YES" : "NO") << '\n';
        }
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

