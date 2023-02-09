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
    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    vector<int> diff;

    for (int i = 0; i < n; ++i)
    {
        if (diff.size() > 0) break;

        vector<int> tmp = a[i];
        sort(tmp.begin(), tmp.end());
        
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] != tmp[j]) diff.push_back(j);
        }
    }

    if (diff.size() > 2)
    {
        cout << "-1\n"; return;
    }

    if (diff.size() == 0)
    {
        cout << 1 << ' ' << 1 << '\n'; return;
    }

    for (int i = 0; i < n; ++i)
    {
        swap(a[i][diff[0]], a[i][diff[1]]);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            if (a[i][j] > a[i][j + 1])
            {
                cout << "-1\n"; return;
            }
        }
    }

    cout << diff[0] + 1 << ' ' << diff[1] + 1 << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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
