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

bool c[30];
int a[maxN];
int f[maxN];

void solve()
{
    memset(c, false, sizeof c);
    memset(a, 0, sizeof a);
    memset(f, 0, sizeof f);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    for (int i = 0; i < k; ++i)
    {
        char u; cin >> u;
        c[u - 'a'] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        a[i] = (c[s[i - 1] - 'a'] ? 1 : 0);
    }

    // PULL DP

    f[0] = 0; // BASE CASE: no substring with an empty string

    for (int i = 1; i <= n; ++i)
    {
        if (a[i]) f[i] = f[i - 1] + 1;
        else f[i] = 0;
    }

    ll res = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        res += f[i];
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

