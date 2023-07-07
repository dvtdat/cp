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

    if (a > b) par[b] = a;
    else par[a] = b;
}

void solve()
{
    int n, q; cin >> n >> q;

    vector<int> par(n + 2);

    for (int i = 1; i <= n + 1; ++i) par[i] = i;

    string order;
    int u;
    while (q--)
    {
        cin >> order >> u;
        if (order == "-") unite(u, u + 1, par);
        else
        {
            int res = get(u, par);
            if (res > n) cout << -1 << '\n';
            else cout << res << '\n';
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

