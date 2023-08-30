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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<ll> f(n + 1, 0);
    f[1] = a[1];

    int mx = 0;

    for (int i = 2; i <= n; ++i)
    {
        mx = a[i];
        for (int j = i; j >= i - k + 1; --j)
        {
            if (j < 1) continue;
            mx = max(mx, a[j]);
            f[i] = max(f[i], 1LL * f[j - 1] + 1LL * mx * (i - j + 1));
        }
    }

    // for (int i = 0; i <= n; ++i) cout << f[i] << ' '; cout << '\n';
    cout << f[n] << '\n';
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("teamwork");
    int test = 1; //cin >> test;
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

