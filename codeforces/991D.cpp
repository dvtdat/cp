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
    string s;
    cin >> s;
    
    int n = s.length();
    vector<vector<int>> a(2, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'X') a[0][i] = 1;
    }

    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'X') a[1][i] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[0][i] || a[1][i]) continue;

        if (i > 0 && !a[0][i - 1])
        {
            a[0][i - 1] = a[0][i] = a[1][i] = 1; cnt++; continue;
        }

        if (i > 0 && !a[1][i - 1])
        {
            a[1][i - 1] = a[0][i] = a[1][i] = 1; cnt++; continue;
        }

        if (i + 1 < n && !a[0][i + 1])
        {
            a[0][i + 1] = a[0][i] = a[1][i] = 1; cnt++; continue;
        }

        if (i + 1 < n && !a[1][i + 1])
        {
            a[1][i + 1] = a[0][i] = a[1][i] = 1; cnt++; continue;
        }
    }

    cout << cnt << '\n';
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

