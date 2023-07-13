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

int pre[200][200];
int a[200], k[200];

void solve()
{
    memset(pre, 0, sizeof pre);
    memset(a, 0, sizeof a);
    memset(k, 0, sizeof k);

    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> k[i];

    for (int i = 1; i <= m; ++i)
    {
        pre[i][1] = (a[1] == i ? 1 : 0);
        for (int j = 2; j <= n; ++j)
        {
            pre[i][j] = pre[i][j - 1] + (a[j] == i ? 1 : 0);
        }
    }
    
    for (int i = 0; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            bool flag = true;
            for (int l = 1; l <= m; ++l)
            {
                if (pre[l][j] - pre[l][i] != k[l]) flag = false;
            }
            if (flag)
            {
                cout << "YES\n"; return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
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

