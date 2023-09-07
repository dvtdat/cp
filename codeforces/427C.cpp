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
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

vector<int> val, comp, z, cont;
int Time, ncomps;

template<class G, class F>
int dfs(int j, G& g, F& f)
{
    int low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j])
    {
        if (comp[e] < 0) low = min(low, val[e] ?: dfs(e, g, f));
    }

    if (low == val[j])
    {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);

        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}

template<class G, class F>
void scc(G& g, F& f)
{
    int n = g.size();
    val.assign(n, 0);
    comp.assign(n, -1);

    Time = ncomps = 0;
    for (int i = 0; i < n; ++i)
    {
        if (comp[i] < 0) dfs(i, g, f);
    }
}

ll total = 0;
ll res = 1;
vector<int> a;

void process(const vector<int>& scc)
{
    int mn = inf;
    for (int node : scc)
    {
        mn = min(mn, a[node]);
    }

    int cnt = 0;
    for (int node : scc)
    {
        if (a[node] == mn) cnt++;
    }

    total += 1LL * mn;
    (res *= 1LL * cnt) %= MOD;
}

void solve()
{
    int n, m; cin >> n;

    a = vector<int>(n);
    vector<vector<int>> adj(n, vector<int>());

    for (int &i : a) cin >> i;

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }

    scc(adj, process);

    cout << total << ' ' << res % MOD << '\n';
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

