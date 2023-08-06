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
const int lim = 1e9;

vector<int> adj[maxN];
int d[maxN];
bool visited[maxN];

void bfs()
{
    queue<int> q;
    q.push(0);

    d[0] = 0;
    visited[0] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v]) continue;
            visited[v] = true;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

void solve()
{
    memset(d, -1, sizeof d);
    memset(visited, false, sizeof visited);
    int n; cin >> n;
    int xa, xb, ya, yb; cin >> xa >> ya >> xb >> yb;

    map<int, int> list;
    int cnt = 2;

    list[xa] = cnt++;
    list[ya + lim] = cnt++;
    list[xb] = cnt++;
    list[yb + lim] = cnt++;

    adj[0].push_back(list[xa]);
    adj[0].push_back(list[ya + lim]);
    adj[list[xb]].push_back(1);
    adj[list[yb + lim]].push_back(1);

    for (int i = 0; i < n; ++i)
    {
        int x, y; cin >> x >> y;

        if (!list[x]) list[x] = cnt++;
        if (!list[y + lim]) list[y + lim] = cnt++;

        adj[list[x]].push_back(list[y + lim]);
        adj[list[y + lim]].push_back(list[x]);
    }

    bfs();

    cout << (d[1] == -1 ? -1 : d[1] - 2) << '\n'; 
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
    setIO("lasers");
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

