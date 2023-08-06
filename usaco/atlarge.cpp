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
int dist1[maxN], dist2[maxN];
int cnt[maxN];

void solve()
{
    memset(cnt, 0, sizeof cnt);
    memset(dist1, -1, sizeof dist1);
    memset(dist2, -1, sizeof dist2);
    memset(visited, false, sizeof visited);

    int n, k; cin >> n >> k;
    k--;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++, cnt[v]++;
    }

    vector<int> exit;
    for (int i = 0; i < maxN; ++i)
    {
        if (cnt[i] == 1) exit.push_back(i);
    }
    
    queue<int> q;
    q.push(k);
    dist1[k] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : adj[u])
        {
            if (dist1[v] != -1) continue;
            dist1[v] = dist1[u] + 1;
            q.push(v);
        }
    }

    q = queue<int>();
    for (int i : exit) q.push(i), dist2[i] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : adj[u])
        {
            if (dist2[v] != -1) continue;
            dist2[v] = dist2[u] + 1;
            q.push(v);
        }
    }

    q = queue<int>();
    q.push(k);
    int res = 0;
    
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        if (dist1[u] >= dist2[u])
        {
            res++;
            continue;
        }

        for (int v : adj[u])
        {
            if (visited[v]) continue;
            q.push(v);
        }
    }

    cout << res << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("atlarge");
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

