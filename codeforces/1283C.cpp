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

int f[maxN];
bool visited[maxN];
int siz[maxN];

int dfs(int s, int& sz)
{
    if (visited[s] || f[s] == -1) return s;
    visited[s] = true;
    sz += 1;
    return dfs(f[s], sz);
}

void solve()
{
    int n; cin >> n;
    vector<int> mark(n, 0);
    vector<int> start, end;

    memset(f, -1, sizeof f);
    memset(visited, false, sizeof visited);
    memset(siz, 0, sizeof siz);

    for (int i = 0; i < n; ++i)
    {
        int u; cin >> u; u--;
        f[i] = u;

        if (u != -1) mark[u] = 1;
    }

    vector<int> s;
    for (int i = 0; i < n; ++i)
    {
        if (!mark[i]) s.push_back(i);
    }

    for (int i = 0; i < s.size(); ++i)
    {
        int v = s[i];
        int u = dfs(v, siz[i]);
        if (u != v || siz[i] == 0) start.push_back(v), end.push_back(u);
    }

    for (int i = 0; i < start.size() - 1; ++i)
    {
        f[end[i]] = start[i + 1];
    }
    f[end[start.size() - 1]] = start[0];

    for (int i = 0; i < n; ++i)
    {
        cout << f[i] + 1 << ' ';
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

