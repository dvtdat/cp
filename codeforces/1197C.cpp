// waiting for love?

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n - 1);

    ll sum = 0;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i)
    {
        b[i - 1] = a[i] - a[i - 1];
        sum += b[i - 1];
    }

    sort(b.rbegin(), b.rend());

    for (int i = 0; i < k - 1; ++i) sum -= b[i];

    cout << sum;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

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

