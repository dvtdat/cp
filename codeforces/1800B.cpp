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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> a(30, 0), A(30, 0);

    for (int i = 0; i < n; ++i)
    {
        if ('a' <= s[i] && s[i] <= 'z') a[s[i] - 'a']++;
        else A[s[i] - 'A']++;
    }

    ll res = 0;

    for (int i = 0; i < 'z' - 'a' + 1; ++i)
    {
        int tmp = min(a[i], A[i]);
        res += tmp;
        a[i] -= tmp;
        A[i] -= tmp;
    }

    for (int i = 0; i < 'z' - 'a' + 1 && k > 0; ++i)
    {
        int tmp = max(a[i], A[i]) / 2;
        res += min(k, tmp);
        k -= min(k, tmp);
    }

    cout << res << '\n';
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

