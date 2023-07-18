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

int a[maxN][3], f[maxN][3];

void solve()
{
    memset(f, 0, sizeof f);
    memset(a, 0, sizeof a);

    // PULL DP

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    f[0][0] = a[0][0];
    f[0][1] = a[0][1];
    f[0][2] = a[0][2];

    for (int i = 1; i < n; ++i)
    {
        f[i][0] = a[i][0] + max(f[i - 1][1], f[i - 1][2]);
        f[i][1] = a[i][1] + max(f[i - 1][0], f[i - 1][2]);
        f[i][2] = a[i][2] + max(f[i - 1][1], f[i - 1][0]);
    }

    cout << max(f[n - 1][0], max(f[n - 1][1], f[n - 1][2])) << '\n';
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

