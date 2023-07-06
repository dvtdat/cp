// hoa' ra em o day

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
    if (par[a] == a) return a;
    return par[a] = get(par[a], par);
}

void unite(const int &a, const int &b, vector<int> &par)
{
    par[get(b, par)] = get(a, par);
};

int monkey[maxN][5];

void solve()
{
    int n, m; cin >> n >> m;
    
    vector<int> par(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        par[i] = i;
    }

    vector<ii> add;
    map<ii, int> init;

    for (int i = 1; i <= n; ++i)
    {
        int u, v; cin >> u >> v;
        monkey[i][1] = u;
        monkey[i][2] = v;

        if (u != -1) init[ii(min(i, u), max(i, u))]++;
        if (v != -1) init[ii(min(i, v), max(i, v))]++;
    }

    for (int i = 0; i < m; ++i)
    {
        int u, hand; cin >> u >> hand;
        int v = monkey[u][hand];

        init[ii(min(u, v), max(u, v))]--;
        add.push_back(ii(u, v));
    }
    reverse(add.begin(), add.end());

    for (auto i : init)
    {
        if (i.second > 0) unite(i.first.first, i.first.second, par);
    }

    vector<int> res(n + 1, 0);
    vector<int> list[n + 1];

    int tmp = get(1, par);
    for (int i = 1; i <= n; ++i)
    {
        if (get(i, par) == tmp) res[i] = -1;
        list[get(i, par)].push_back(i);
    }

    for (int i = 0; i < m; ++i)
    {
        int u = get(add[i].first, par);
        int v = get(add[i].second, par);

        if (u == v) continue;

        if (list[u].size() < list[v].size()) swap(u, v);

        if (v == get(1, par)) 
        {
            for (int j = 0; j < list[u].size(); ++j) 
            {
                if (res[list[u][j]] == 0) res[list[u][j]] = m - i - 1;
            }
        }

        if (u == get(1, par)) 
        {
            for (int j = 0; j < list[v].size(); ++j)
            {
                if (res[list[v][j]] == 0) res[list[v][j]] = m - i - 1;
            }
        }

        unite(u, v, par);
        for (int j = 0; j < list[v].size(); ++j) list[u].push_back(list[v][j]);
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << res[i] << '\n';
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

