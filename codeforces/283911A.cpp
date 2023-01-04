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
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < k; ++i)
    {
        int x; cin >> x;
        bool ok = false;

        int l = 0, r = n - 1;

        while (r >= l)
        {
            int mid = (l + r) / 2;
            if (a[mid] == x)
            {
                ok = true;
                break;
            }
            else if (a[mid] < x)
            {
                l = mid + 1;
            }
            else r = mid - 1;
        }

        cout << (ok ? "YES\n" : "NO\n");
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


