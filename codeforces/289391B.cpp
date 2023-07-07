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

void unite(int a, int b, vector<int> &par)
{
    a = get(a, par);
    b = get(b, par);

    par[b] = a; // a is the parent of b, with guaranteed input
}

void solve()
{
    int n; cin >> n;

    vector<int> par(n + 2);

    for (int i = 1; i <= n + 1; ++i) par[i] = i;
    unite(1, n + 1, par);

    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u;
        int res = get(u, par);
        unite(res + 1, res, par);

        cout << res << ' ';
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

