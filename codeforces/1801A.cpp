// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    vector<vector<int>> a(300, vector<int>(300, 0));

    int cnt = 0;
    for (int i = 0; i < 256; i += 2)
    {
        for (int j = 0; j < 256; j += 2)
        {
            a[i][j] = cnt++;
            a[i][j + 1] = cnt++;
            a[i + 1][j] = cnt++;
            a[i + 1][j + 1] = cnt++;
        }
    }

    int test; cin >> test;
    while (test--)
    {
        int n, m; cin >> n >> m;
        cout << n * m << '\n';
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

int main()
{
    setIO("text");
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

