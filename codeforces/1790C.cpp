// 

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
const int maxN = 210;
const ll MOD = 998244353;
const double eps = 1e-12;

int cnt[maxN][maxN];
int vis[maxN];

void solve()
{  
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);

    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            int u; cin >> u;
            cnt[j][u]++;
        }
    }

    int pos1 = 0, mx = 0, pos2 = 0, mn = inf;
    vector<int> res;

    for (int i = 0; i < n - 1; ++i)
    {
        pos1 = 0, mx = 0;
        pos2 = 0, mn = inf;

        for (int j = 1; j <= n; ++j)
        {
            if (mx < cnt[i][j])
            {
                mx = cnt[i][j];
                pos1 = j;
            }
            if (mn >= cnt[i][j] && cnt[i][j] != 0)
            {
                mn = cnt[i][j];
                pos2 = j;
            }
        }

        if (!vis[pos1]) 
        {
            res.push_back(pos1);
            vis[pos1] = 1;
        }

        if (!vis[pos2]) 
        {
            res.push_back(pos2);
            vis[pos2] = 1;
        }
    }

    for (int i : res) cout << i << ' ';

    cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
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

