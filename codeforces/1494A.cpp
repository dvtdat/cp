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

    int first = s[0] - 'A' + 1, last = s[s.length() - 1] - 'A' + 1;
    vector<int> a(4), d(4, 0);

    for (int i = 0; i < s.length(); ++i)
    {
        a[s[i] - 'A' + 1]++;
    }
    
    if (first == last)
    {
        cout << "NO\n"; return;
    }

    if (a[first] == s.length() / 2)
    {
        if (first == 1) d[1] = 1, d[2] = d[3] = -1;
        if (first == 2) d[2] = 1, d[1] = d[3] = -1;
        if (first == 3) d[3] = 1, d[1] = d[2] = -1;
    }
    else
    {
        if (last == 1) d[2] = d[3] = 1, d[1] = -1;
        if (last == 2) d[1] = d[3] = 1, d[2] = -1;
        if (last == 3) d[1] = d[2] = 1, d[3] = -1;  
    }

    int cnt = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        cnt += d[s[i] - 'A' + 1];
        if (cnt < 0)
        {
            cout << "NO\n"; return;
        }
    }

    if (cnt == 0) cout << "YES\n";
    else cout << "NO\n";
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

