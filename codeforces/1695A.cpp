// chill

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
    int n, m; cin >> n >> m;

    int mx = -infLL;
    long long area;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int t; cin >> t;
            if (t > mx)
            {
                mx = t;
                area = 1LL* max(i + 1, n - i) * max(j + 1, m - j);
            }
            else if (t == mx)
            {
                area = max(area, 1LL * max(i + 1, n - i) * max(j + 1, m - j));
            }
        }
    }

    cout << area << '\n';
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

