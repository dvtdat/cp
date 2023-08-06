// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 50010;
const ll MOD = 998244353;
const double eps = 1e-12;

vector<int> adj[maxN];
vector<int> dB(maxN), dE(maxN), dD(maxN);

void bfs(int s, vector<int> &d)
{
    d = vector<int>(maxN, -1);
    // for (int i = 0; i < 10; ++i) cout << d[i] << ' '; cout << '\n';
    queue<ii> q;
    q.push(ii(s, 0));
    d[s] = 0;

    while (!q.empty())
    {
        int u = q.front().first;
        int w = q.front().second;
        q.pop();

        for (int v : adj[u])
        {
            if (d[v] != -1) continue;
            d[v] = w + 1;
            q.push(ii(v, d[v]));
        }
    }
    // for (int i = 0; i < 10; ++i) cout << d[i] << ' '; cout << '\n';
}

void solve()
{
    int B, E, P, n, m;
    cin >> B >> E >> P >> n >> m;

    while (m--)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(0, dB);
    bfs(1, dE);
    bfs(n - 1, dD);

    int res = inf;
    for (int i = 0; i < n; ++i)
    {
        // cout << B * dB[i] + E * dE[i] + P * dD[i] << '\n';
        res = min(res, B * dB[i] + E * dE[i] + P * dD[i]);
    }

    cout << res << '\n';
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

