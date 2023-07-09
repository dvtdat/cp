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

set<ll> val;

void solve()
{
    for (ll k = 2; k <= 1000000; ++k)
    {
        ll kk = k * k;
        ll tmp = 1 + k;
        for (ll h = 3; h <= 63; ++h)
        {
            tmp += kk;
            if (tmp > 1e18) break;

            val.insert(tmp);
            if (kk > (ll)(1e18) / k) break;
            kk *= k;
        }
    }

    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        if (n < 7)
        {
            cout << "NO\n"; continue;
        }

        if (val.count(n))
        {
            cout << "YES\n"; continue;
        }

        ll d = 4 * n - 3;
        ll tmp = sqrt(4 * n - 3);
        ll res = -1;

        for (ll i = max(0LL, tmp - 5); i <= tmp + 5; ++i)
        {
            if (i * i == d)
            {
                res = i; break;
            }
        }

        if (res != -1 && (-1 + res) % 2 == 0 && (res - 1) / 2 > 1)
        {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test = 1;
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

