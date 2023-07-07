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
    ll n, m; cin >> n >> m;
    ll newN = n;
    ll k = 1;

    int cnt2 = 0, cnt5 = 0;
    while (n % 2 == 0 && n != 0)
    {
        n = n / 2;
        cnt2++;
    }

    while (n % 5 == 0 && n != 0)
    {
        n = n / 5;
        cnt5++;
    }

    while (cnt2 < cnt5 && k * 2 <= m)
    {
        k = k * 2;
        cnt2++;
    }

    while (cnt2 > cnt5 && k * 5 <= m)
    {
        k = k * 5;
        cnt5++;
    }

    while (k * 10 <= m)
    {
        k = k * 10;
    }

    if (k == 1) cout << newN * m << '\n';
    else
    {
        if (m / k < 10) k = k * (m / k); // maximize
        cout << newN * k << '\n';
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

