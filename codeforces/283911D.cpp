//

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 100010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int k; cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int x, y; cin >> x >> y;
        int lower, upper;
        // finding  the lowerbound
        int l = -1, r = n;
        while (r - 1 > l)
        {
            int mid = (l + r) / 2;
            if (a[mid] < x) l = mid;
            else r = mid;
        }

        lower = r;

        l = -1, r = n;
        while (r - 1 > l)
        {
            int mid = (l + r) / 2;
            if (a[mid] <= y) l = mid;
            else r = mid;
        }

        upper = r;

        cout << upper - lower << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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


