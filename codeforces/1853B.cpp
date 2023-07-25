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
    int n, k; cin >> n >> k;
    if (k > 40)
    {
        cout << 0 << '\n'; return;
    }

    int res = 0;
    for (int i = 0; i <= n; ++i)
    {
        vector<int> f(k + 1, 0);
        bool flag = true;

        f[k] = n; f[k - 1] = i;
        
        for (int j = k - 2; j > 0; --j)
        {
            f[j] = f[j + 2] - f[j + 1];
            if (f[j] < 0 || f[j] > f[j + 1]) flag = false;
        }
        
        if (flag) res++;
    }

    cout << res << '\n';
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

