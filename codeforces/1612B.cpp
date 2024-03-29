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
    int n, a, b; cin >> n >> a >> b;

    vector<int> v;
    v.push_back(a);
    for (int i = n / 2 + 1; i <= n; ++i)
        if (i != a && i != b) v.push_back(i);

    v.push_back(b);
    for (int i = 1; i <= n / 2; ++i)
        if (i != a && i != b) v.push_back(i);

    int mn = inf, mx = 0;

    for (int i = 0; i < n / 2; ++i) mn = min(mn, v[i]);
    for (int i = n / 2; i < n; ++i) mx = max(mx, v[i]);

    if (v.size() == n && mn == a && mx == b)
    {
        for (int i = 0; i < n; ++i) cout << v[i] << ' ';
    }
    else cout << -1;

    cout << '\n';
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

