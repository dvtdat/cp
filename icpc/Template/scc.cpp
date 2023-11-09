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

void process(const vector<int>& scc)
{
    cout << "SCC:";
    for (int node : scc)
    {
        cout << " " << node;
    }
    cout << '\n';
}

int main()
{
    int n = 8;
    vector<vector<int>> adj(8, vector<int>());

    /*
    1 2
    2 3
    3 1
    6 1
    6 4
    4 5
    7 6
    */

    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[6].push_back(1);
    adj[6].push_back(4);
    adj[4].push_back(5);
    adj[7].push_back(6);

    scc(adj, process);
}