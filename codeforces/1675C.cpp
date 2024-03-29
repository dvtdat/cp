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
    string s; cin >> s;
    int n = s.length();
    int t = 0;

    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0') flag = true;
        if (flag && s[i] == '?') s[i] = '0';
    }

    flag = false;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '1') flag = true;
        if (flag && s[i] == '?') s[i] = '1';
    }

    // cout << s << '\n';

    int res = 0;
    int one = 0;
    int zero = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0') zero++;
        if (s[i] == '1') one++;
        if (s[i] == '?') res++;
    }

    if (one == n || zero == n)
    {
        cout << 1 << '\n'; return;
    }

    if (res == n)
    {
        cout << n << '\n';
        return;
    }

    if (s[0] == '?' || s[n - 1] == '?') res--;
    
    cout << res + 2 << '\n';
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

