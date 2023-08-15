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
    vector<int> a(n + 1, 0), f(n + 1, inf);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    f[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int upper1 = upper_bound(a.begin(), a.end(), a[i] - 90) - a.begin();
        int upper2 = upper_bound(a.begin(), a.end(), a[i] - 1440) - a.begin();

        upper1 = max(0, upper1 - 1);
        upper2 = max(0, upper2 - 1);
        
        f[i] = f[i - 1] + 20;
        f[i] = min(f[i], f[upper1] + 50);
        f[i] = min(f[i], f[upper2] + 120);
    }

    cout << f[1] << '\n';
    for (int i = 2; i <= n; ++i) cout << f[i] - f[i - 1] << '\n';
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

