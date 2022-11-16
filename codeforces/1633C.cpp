// "giong nhu LK tao van tu hoi? nhieu` khi Den Vau la` ai"

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
    long long hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;

    long long l = 0, r = k, i;

    bool flag = 0;

    for (i = 0; i <= k; ++i)
    {
        if ((hc + i * a) / dm + ((hc + i * a) % dm ? 1 : 0) >= hm / (dc + (k - i) * w) + (hm % (dc + (k - i) * w) ? 1 : 0))
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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

