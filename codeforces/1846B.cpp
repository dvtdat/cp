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

char c[4][4];

void solve()
{
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            cin >> c[i][j];
        }
    }

    bool flag = true;
    for (int i = 1; i <= 3; ++i)
    {
        flag = true;
        for (int j = 1; j <= 3; ++j)
        {
            if (c[i][j] != c[i][1] || c[i][1] == '.' || c[i][j] == '.') flag = false;
        }

        if (flag)
        {
            cout << c[i][1] << "\n"; return;
        }
    }

    for (int j = 1; j <= 3; ++j)
    {
        flag = true;
        for (int i = 1; i <= 3; ++i)
        {
            if (c[i][j] != c[1][j] || c[1][j] == '.' || c[i][j] == '.') flag = false;
        }

        if (flag)
        {
            cout << c[1][j] << "\n"; return;
        }
    }

    flag = true;    
    for (int i = 1; i <= 3; ++i)
    {
        if (c[i][i] != c[1][1] || c[1][1] == '.' || c[i][i] == '.') flag = false;
    }

    if (flag)
    {
        cout << c[1][1] << '\n'; return;
    }

    flag = true;
    for (int i = 1; i <= 3; ++i)
    {
        if (c[i][3 - i + 1] != c[3][1] || c[3][1] == '.' || c[i][3 - i + 1] == '.') flag = false;
    }

    if (flag)
    {
        cout << c[3][1]<< '\n'; return;
    }

    cout << "DRAW\n";
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

