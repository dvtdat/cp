// khong coi no' la` thoi' quen, khong hieu sao, van~ kho' sua

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
    int n; cin >> n;

    if (n % 7 == 0)
    {
        cout << n << '\n'; return;
    }

    n = n / 10 * 10;

    for (int i = 0; i < 10; ++i)
    {
        if ((n + i) % 7 == 0)
        {
            cout << n + i << '\n';
            return;
        }
    }
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

