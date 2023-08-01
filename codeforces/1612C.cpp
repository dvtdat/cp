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
ll n, x; 

void solve()
{
    cin >> n >> x;

    if (n == 1)
    {
        cout << 1 << '\n'; return;
    }

    ll l = 1, r = 2 * n - 1;
    ll res = 2 * n - 1;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        
        if (mid >= n)
        {
            ll t = 2 * n - 1 - mid;
            if (n * (n + 1) / 2 + n * (n - 1) / 2 - t * (t + 1) / 2 < x) l = mid + 1;
            else r = mid - 1, res = mid;
        }
        else
        {
            if (mid * (mid + 1) / 2 < x) l = mid + 1;
            else r = mid - 1, res = mid;
        }
    }
    cout << res << '\n';
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

