//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

ll a[maxN];

void solve()
{
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n);

    for (int i = 1; i < n; ++i)
    {
        if (a[0] < a[i]) a[0] += (a[i] - a[0]) / 2 + (a[i] - a[0]) % 2;
    }

    cout << a[0] << '\n';
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

