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
    ll n, p, k; cin >> n >> p >> k;
    vector<ll> a(n + 1), f(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    f[0] = 0;
    f[1] = a[1];
    for (int i = 2; i <= k - 1; ++i) f[i] = f[i - 1] + a[i];

    for (int i = k; i <= n; ++i) f[i] = f[i - k] + a[i];

    for (int i = n; i >= 0; --i)
    {
        if (f[i] <= p)
        {
            cout << i << '\n'; return;
        }
    }
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
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

