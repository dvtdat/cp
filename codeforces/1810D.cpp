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
    int q; cin >> q;
    ll mn = 0, mx = infLL;

    ll order, a, b, n;
    ll lowerH, upperH;

    while (q--)
    {
        cin >> order;
        if (order == 1)
        {
            cin >> a >> b >> n;
            lowerH = 1LL * (a - b) * (n - 2) + a + 1;
            upperH = 1LL * (a - b) * (n - 1) + a;

            if (n == 1) lowerH = 1, upperH = a;

            if (upperH < mn || mx < lowerH)
            {
                cout << 0 << ' ';
                continue;
            }

            cout << 1 << ' ';
            mn = max(lowerH, mn);
            mx = min(upperH, mx);
            continue;
        }

        cin >> a >> b;

        ll upperT = 1LL * (mx - a + (a - b - 1)) / (a - b) + 1;
        ll lowerT = 1LL * (mn - a + (a - b - 1)) / (a - b) + 1;
        upperT = max(upperT, 1LL);
        lowerT = max(lowerT, 1LL);

        // cout << mn << ' ' << mx << ' ' << lowerT << ' ' << upperT << '\n';

        if (upperT != lowerT) cout << -1 << ' ';
        else cout << upperT << ' ';
    }

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

