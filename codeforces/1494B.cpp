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
    int n, u, l, d, r; cin >> n >> u >> l >> d >> r;
    
    for (int i = 0; i < 16; ++i)
    {
        int nU = u, nL = l, nD = d, nR = r;
        if ((1 << 0) & i)
        {
            nU--; nL--;
        }
        if ((1 << 1) & i)
        {
            nL--; nD--;
        }
        if ((1 << 2) & i)
        {
            nD--; nR--;
        }
        if ((1 << 3) & i)
        {
            nR--; nU--;
        }

        if (0 <= nU && nU <= n - 2 && 0 <= nL && nL <= n - 2 && 0 <= nD && nD <= n - 2 && 0 <= nR && nR <= n - 2)
        {
            cout << "YES\n"; return;
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

