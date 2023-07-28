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

vector<ii> adj[maxN];
int d[maxN];
bool visited[maxN];
bool flag = true;

void bfs(int s)
{
    queue<ii> q; q.push(ii(s, 1));
    d[s] = 1;

    while (!q.empty())
    {
        int u = q.front().first;
        int uType = q.front().second;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int i = 0; i < (int)adj[u].size(); ++i)
        {
            int v = adj[u][i].first;
            int vType = adj[u][i].second ? uType : !uType;

            if (!visited[v])
            {
                d[v] = vType;
                q.push(ii(v, vType));
                continue;
            }
            
            if (d[v] != vType)
            {
                flag = false;
                return;
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        char c;
        int u, v;
        cin >> c >> u >> v;
        u--, v--;

        int type = (c == 'S' ? 1 : 0);
        adj[u].push_back(ii(v, type));
        adj[v].push_back(ii(u, type));
    }

    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i]) continue;
        bfs(i);
        res++;
    }

    if (!flag)
    {
        cout << 0 << '\n'; return;
    }

    cout << 1;
    for (int i = 0; i < res; ++i) cout << 0;
    cout << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

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

