// WRONG ANSWER

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
    ll n, l, r, s; cin >> n >> l >> r >> s;
    ll k = r - l + 1;

    vector<vector<ll>> f(k + 1, vector<ll>(s + 1, 0));

    f[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = k; j >= 1; --j)
        {
            for (int t = s; t >= i; --t)
            {
                f[j][t] += f[j - 1][t - i];
            }
        }
    }

    if (f[k][s] == 0)
    {
        cout << -1 << '\n'; return;
    }

    vector<ll> res(n + 2, 0);
    vector<bool> ok(n + 2, false);
    int idx = l;
    for (int i = 1; i <= n && k > 0 && s > 0; ++i)
    {
        if (f[k - 1][s - i] > 0)
        {
            res[idx++] = i;
            ok[i] = true;
            --k;
            s -= i;
        }
    }

    ll tmp = 1;
    ll i = 1;

    while (i <= n)
    {
        if (res[i])
        {
            i++;
            continue;
        }
        while (ok[tmp]) tmp++;

        res[i] = tmp;
        tmp++;
    }

    for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << '\n';
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

