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

int check[3][3] = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};

void solve()
{
    ll n, k; cin >> n >> k;

    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    sort(a.begin(), a.end());

    ll res = 0;

    for (ll i = 0; i < 3; ++i)
    {
        ll m = 0;
        ll kk = k;
        for (ll j = 0; j < n; ++j)
        {
            while (kk <= a[j] && m < 3)
            {
                kk *= check[i][m];
                m++;
            }

            if (kk > a[j])
            {
                kk += a[j] / 2;
                res = max(res, j + 1);
            }
            // cout << kk << ' ';
        }
        // cout << '\n';
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

