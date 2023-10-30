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
    int n; cin >> n;
    string a, b; cin >> a >> b;

    int diff = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i]) cnt1 += (a[i] - '0');
        else diff++, cnt2 += (a[i] - '0');
    }

    int res = inf;
    if (cnt1 * 2 - 1 == n - diff) res = min(res, n - diff);
    if (cnt2 * 2 == diff) res = min(res, diff);
    
    if (res == inf) cout << -1 << '\n';
    else cout << res << '\n';
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

