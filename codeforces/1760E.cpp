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
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b = a;

    ll k = 0;
    ll cnt = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] == 0) k++;
        else cnt += k;
    }

    b = a;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            break;
        }
    }

    k = 0;
    ll res = cnt;
    cnt = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] == 0) k++;
        else cnt += k;
    }
    
    b = a;
    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] == 1)
        {
            b[i] = 0;
            break;
        }
    }

    k = 0;
    res = max(res, cnt);
    cnt = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] == 0) k++;
        else cnt += k;
    }

    cout << max(res, cnt) << '\n';
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

