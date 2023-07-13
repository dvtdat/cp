//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 1e9 + 7;
const int maxN = 100010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int l = -1, r = inf;
    while (r - 1 > l)
    {
        int m = (l + r) / 2;
        int i = 0, j = n - 1;

        while (i + 1 < a.size() && a[i + 1] - a[0] <= 2 * m) i++;
        while (j - 1 >= 0 && a[n - 1] - a[j - 1] <= 2 * m) j--;

        i++; j--;
        if (i > j || a[j] - a[i] <= 2 * m) r = m;
        else l = m;
    }

    cout << r << '\n';
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


