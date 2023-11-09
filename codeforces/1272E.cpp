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

void solve()
{
    int n; cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(0));
    vector<int> a(n + 1, 0), res(n + 1, inf), t(n + 1, -1);

    for (int i = 1; i <= n; ++i) 
    {
        cin >> a[i];
        if (i + a[i] <= n) adj[i + a[i]].push_back(i);
        if (i - a[i] > 0) adj[i - a[i]].push_back(i);
        t[i] = (a[i] & 1);
    }

    auto bfs = [&](int isOdd)
    {
        queue<int> q;
        for (int i = 1; i <= n; ++i) 
        {   
            if (!(t[i] ^ isOdd)) q.push(i);
        }
        vector<int> d(n + 1, inf);

        while (q.size())
        {
            int u = q.front(); q.pop();
            for (int v : adj[u])
            {
                if (d[v] != inf) continue;
                if (t[u] == t[v]) d[v] = d[u] + 1;
                else d[v] = 0;
                q.push(v);
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (d[i] == inf || !(t[i] ^ isOdd)) continue;
            res[i] = d[i];
        }
    };

    bfs(1);
    bfs(0);

    for (int i = 1; i <= n; ++i)
    {
        cout << (res[i] >= inf ? -1 : res[i] + 1) << ' ';
    }
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

