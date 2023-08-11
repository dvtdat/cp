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

string s[maxN];
int visited[30];
vector<int> adj[30];
vector<int> topo;

void impossible()
{
    cout << "Impossible\n";
    exit(0);
}

void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (visited[v] == 1) impossible();
        if (visited[v] == 0) dfs(v);
    }

    topo.push_back(u);
    visited[u] = 2;
}

void solve()
{
    memset(visited, 0, sizeof visited);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];

    bool flag = false;
    for (int i = 1; i < n; ++i)
    {
        string x = s[i - 1];
        string y = s[i];
        flag = false;

        for (int k = 0; k < min(x.length(), y.length()); ++k)
        {
            if (x[k] == y[k]) continue;
            adj[x[k] - 'a'].push_back(y[k] - 'a');
            flag = true;
            break;
        }
        if (x.length() > y.length() && !flag) impossible();
    }
    
    for (int i = 0; i < 26; ++i)
    {
        if (visited[i] == 0) dfs(i);
    }
    
    reverse(topo.begin(), topo.end());
    for (int i : topo) cout << (char)(i + 'a');
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

