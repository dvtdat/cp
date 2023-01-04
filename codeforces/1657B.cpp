// teo teo teo

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
    int n, k, x, y; cin >> n >> k >> x >> y;

    vector<int> a(n + 1);
    a[0] = 0;

    ll sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1] + x <= k) a[i] = a[i - 1] + x;
        else a[i] = a[i - 1] - y;

        sum += a[i];
    }

    cout << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

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

