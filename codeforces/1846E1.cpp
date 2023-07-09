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

ll power(ll a, ll b)
{

}

void solve()
{
    ll n; cin >> n;

    if (n == 1)
    {
        cout << "NO\n"; return;
    }

    for (ll k = 2; k <= 1000; ++k)
    {
        ll kk = k * k * k;
        for (ll h = 2; kk <= n * k && h <= 20; ++h)
        {
            if ((k - 1) * n + 1 - kk < 0) break;

            if ((k - 1) * n + 1 - kk == 0)
            {
                // cout << k << ' ' << h << ' ' << kk << ' ';
                cout << "YES\n";
                return;
            }
            kk *= k;
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

