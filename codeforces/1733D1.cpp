// toi thuc su. khong xung' dang' voi' em...

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

int a[maxN], b[maxN];

void solve()
{
    ll n, x, y; cin >> n >> x >> y;

    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for (int i = 0; i < n; ++i) 
    {
        char c; cin >> c; a[i] = c - '0';
    }
    for (int i = 0; i < n; ++i) 
    {
        char c; cin >> c; b[i] = c - '0';
    }

    for (int i = 0; i < n; ++i) a[i] ^= b[i];

    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i]) cnt++;
    }

    if (cnt & 1)
    {
        cout << -1 << '\n'; return;
    }

    if (cnt == 2)
    {
        for (int i = 0; i < n - 1; ++i) 
            if (a[i] == 1 && a[i + 1] == 1)
            {
                cout << min(x, 2 * y) << '\n'; return;
            }
    }

    cout << cnt / 2 * y << '\n';
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
