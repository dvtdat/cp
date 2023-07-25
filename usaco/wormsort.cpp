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

vector<int> adj[maxN];
int visited[maxN];

void reset()
{
    for (int i = 0; i < maxN; ++i) adj[i].clear();
    memset(visited, 0, sizeof visited);
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = s;

        for (int v : adj[u])
        {
            if (!visited[v]) q.push(v);
        }
    }
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    vector<ii> edge(k + 1);
    vector<int> weight(k + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= k; ++i)
    {
        int u, v, w; cin >> u >> v >> w;
        edge[i].first = u;
        edge[i].second = v;
        weight[i] = w; 
    }

    int l = 0, r = 1e9 + 7;

    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        bool flag = true;

        // cout << mid << '\n';

        reset();
        for (int i = 1; i <= k; ++i)
        {
            if (weight[i] >= mid)
            {
                adj[edge[i].first].push_back(edge[i].second);                
                adj[edge[i].second].push_back(edge[i].first);                
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i]) bfs(i);
        }

        // for (int i = 1; i <= n; ++i) cout << visited[i] << ' '; cout << '\n';

        for (int i = 1; i <= n; ++i)
        {
            if (visited[a[i]] == visited[i]) continue;
            flag = false; break;
        }

        if (flag) l = mid;
        else r = mid;
    }

    cout << (l >= 1e9 ? -1 : l) << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
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

