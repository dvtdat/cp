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
    int n;
    string s;
    cin >> n >> s;

    ll res = 0;

    for (int i = 0; i < n; ++i)
    {
        vector<int> f(10, 0);
        int dist = 0;
        int mx = 0;

        for (int j = i; j < n; ++j)
        {
            f[s[j] - '0']++;
            if (f[s[j] - '0'] > 10) break;

            if (f[s[j] - '0'] == 1) dist++;
            mx = max(mx , f[s[j] - '0']);

            if (dist >= mx) res++;
        }
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

