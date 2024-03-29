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

int x[maxN];
int y[maxN];
int p[maxN];
vector<int> adj1[maxN];
bool visited[maxN];

float dis(int a, int b)
{
    return 1.0 * sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int bfs(int s)
{
    memset(visited, false, sizeof visited);

    queue<int> q;
    q.push(s);

    int res = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        res++;
        
        for (int v : adj1[u])
        {
            if (!visited[v]) q.push(v);
        }
    }

    return res;
}

void solve()
{
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(p, 0, sizeof p);

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i] >> p[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (dis(i, j) <= 1.0 * p[i]) adj1[i].push_back(j);
            if (dis(i, j) <= 1.0 * p[j]) adj1[j].push_back(i);
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, bfs(i));
    }

    cout << res << '\n';
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.inp", "r", stdin);
    //     freopen("output.out", "w", stdout);
    // #endif

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
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

