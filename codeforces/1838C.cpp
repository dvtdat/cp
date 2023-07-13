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

    vector<int> a;
    for (int i = 1; i <= 1 + (n - 1) * m; i += m) a.push_back(i);

    vector<int> b, c;
    for (int i = 0; i < a.size() / 2; ++i) b.push_back(a[i]);
    for (int i = a.size() / 2; i < a.size(); ++i) c.push_back(a[i]);

    int k = 0;
    for (int i = 0; i < a.size() / 2; ++i)
    {
        for (int j = 0; j < m; ++j) cout << c[k] + j << ' '; cout << '\n';
        for (int j = 0; j < m; ++j) cout << b[k] + j << ' '; cout << '\n';
        k++;
    }
    if (n & 1)
    {
        for (int j = 0; j < m; ++j) cout << c[n / 2] + j << ' ';
        cout << '\n';
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

