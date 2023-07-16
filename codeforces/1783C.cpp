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

    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> b = a;
    sort(b.begin(), b.end());

    int cnt = 0;
    for (int i = 0; i < n && b[i] <= m; ++i)
    {
        m -= b[i];
        cnt++;
    }

    if (cnt != 0 && cnt != n && m + b[cnt - 1] - a[cnt] >= 0) cnt++;
    cout << n - cnt + 1 << '\n';
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

