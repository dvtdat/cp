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
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);
    ll res = 0;

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a.back() > b[0])
    {
        cout << -1 << '\n';
        return;
    }
    
    for (int i = 0; i < n; ++i) res += 1ll * a[i] * m;
    for (int i = 0; i < m; ++i) res += 1ll * b[i];

    res -= 1ll * a.back() * (m - 1);

    if (a.back() == b[0]) res -= 1ll * a.back();
    else res -= 1ll * a[(int)a.size() - 2];

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

