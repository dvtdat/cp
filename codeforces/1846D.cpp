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
    ll n, d, h; cin >> n >> d >> h;
    
    ll area = d * h;
    ld total = (ld)area;

    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    for (int i = 1; i < n; ++i)
    {
        ll c = max(a[i - 1] + h - a[i], 0LL);
        total += (ld)area;
        if (c == 0LL) continue;
        total -= (ld)(1.0 * (1.0 * c / h) * (1.0 * c / h) * area);
    }

    cout << fixed << setprecision(8);
    cout << 1.0 * total / 2;
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

