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
    int a, b; cin >> a >> b;
    string s; cin >> s;

    int n = s.length();

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0') a--;
        else if (s[i] == '1') b--;
    }

    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] == '1' && s[n - i - 1] == '?') b--, s[n - i - 1] = '1';
        if (s[i] == '?' && s[n - i - 1] == '1') b--, s[i] = '1';

        if (s[i] == '0' && s[n - i - 1] == '?') a--, s[n - i - 1] = '0';
        if (s[i] == '?' && s[n - i - 1] == '0') a--, s[i] = '0';

        if (a < 0 || b < 0)
        {
            cout << -1 << '\n'; return;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == n / 2 && s[i] == '?')
        {
            if (b > a) b -= 1, s[i] = '1';
            else a -= 1, s[i] = '0';            
        }
        else if (s[i] == '?' && s[n - i - 1] == '?')
        {
            if (b > a) b -= 2, s[i] = s[n - i - 1] = '1';
            else a -= 2, s[i] = s[n - i - 1] = '0';
        }
        
        if (a < 0 || b < 0)
        {
            cout << -1 << '\n'; return;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != s[n - i - 1])
        {
            cout << -1 << '\n'; return;
        }
    }

    cout << s << '\n';
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

