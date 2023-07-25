// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 1e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

vector<int> adj[maxN];
int visited[maxN];

void reset()
{
    for (int i = 0; i < maxN; ++i) adj[i].clear();
    for (int i = 0; i < maxN; ++i) visited[i] = -1;
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u] != -1) continue;
        visited[u] = s;

        for (int v : adj[u])
        {
            if (visited[v] == -1) q.push(v);
        }
    }
}

void solve()
{
    reset();

    int n, k; cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == -1) bfs(i);
    }

    // Guarantee visited to be sorted.
    // for (int i = 0; i < n; ++i) cout << visited[i] << ' '; cout << '\n';

    if (visited[0] == visited[n - 1])
    {
        cout << 0 << '\n';
        return;
    }

    vector<vector<int>> root(n);
    for (int i = 0; i < n; ++i)
    {
        root[visited[i]].push_back(i);
    }
    // Guarantee every root[visite[i]] to be sorted as well.

    /*
    
    Idea:
        We have 2 components: one with the source vertex and one with the destination vertex.
        We have some intermediate components: those which aren't connected to the first 2.
        We can brute force or binary search to find the 2 best pair of (i1, j1) and (i2, j2) 
            - From source component to an arbitrary intermediate component (i1, j1)
            - From that arbitrary intermediate component to destination component (i2, j2)
    */

    ll res = infLL;
    vector<ll> srcCost(n, inf);
    vector<ll> desCost(n, inf);

    int srcIdx = 0;
    int desIdx = 0;

    int rootSrc = visited[0];
    int rootDes = visited[n - 1];

    // Listing best solution for (i1, j1)
    /*
        Traversing every vertex of the graph with i (A)
        Traversing every vertex of root[0] with srcIdx (B)
        Minimizing the cost of connecting source root and root of (A)
        If vertex (B) is larger than vertex (A) => no need to check more, we only care about largest index closest to (A)
    */
    for (int i = 0; i < n; ++i) // (A)
    {
        while (srcIdx < root[rootSrc].size()) // (B)
        {
            srcCost[visited[i]] = min(srcCost[visited[i]], (ll)abs(i - root[rootSrc][srcIdx]));
            if (root[rootSrc][srcIdx] < i) srcIdx++;
            else break;
        }
        if (srcIdx) srcIdx--;
    }

    // Listing best solution for (i2, j2)
    for (int i = 0; i < n; ++i)
    {
        while (desIdx < root[rootDes].size())
        {
            desCost[visited[i]] = min(desCost[visited[i]], (ll)abs(i - root[rootDes][desIdx]));
            if (root[rootDes][desIdx] < i) desIdx++;
            else break;
            // no need to check more, we only care about smallest index closest to (A)
        }
        if (desIdx) desIdx--;
    }

    for (int i = 0; i < n; ++i) res = min(res, srcCost[i] * srcCost[i] + desCost[i] * desCost[i]);
    cout << res << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
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

