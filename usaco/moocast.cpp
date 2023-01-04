//NOT DONE
//PLS DONE USE THIS
//NOT DONE

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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
bool visited[maxN];
int cnt = 0;

struct cowStuct
{
    int x, y, p;
};

void dfs(int u)
{
    if (visited[u]) return;

    cnt++;
    visited[u] = true;

    for (int v : adj[u])
    {
        if (!visited[v]) dfs(v);
    }
}

void solve()
{
    int n; cin >> n;

    vector<cowStuct> cow(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> cow[i].x >> cow[i].y >> cow[i].p;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int x = cow[i].x - cow[j].x;
            int y = cow[i].y - cow[j].y;

            if (x * x + y * y <= cow[i].p * cow[i].p) adj[i].push_back(j);
            else if (x * x + y * y <= cow[j].p * cow[j].p) adj[j].push_back(i);
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        memset(visited, false, sizeof visited);
        cnt = 0;
        dfs(i);
        res = max(res, cnt);
    }

    cout << res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        //freopen("moocast.out", "w", stdout);
    #endif
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

