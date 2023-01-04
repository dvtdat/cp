// wish me luck

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
    int x, y; cin >> x >> y;

    if (x == 0 && y == 0)
    {
        cout << 0 << '\n';
        return;
    }

    if (1.0 * sqrt(x * x + y * y) - (int)sqrt(x * x + y * y) > 0.0) cout << 2;
    else cout << 1;

    cout << '\n';
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

