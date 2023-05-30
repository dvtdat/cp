// 

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
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

class ModOp
{
public:
    int add(int x, int y)
    {
        return ((x + y) % MOD + MOD) % MOD;
    }

    int sub(int x, int y)
    {
        return add(x, -y);
    }

    int mul(int x, int y)
    {
        return x * 1LL * y % MOD;
    }

    int binpow(int x, int y)
    {
        int z = 1;
        while (y)
        {
            if (y % 2 == 1) z = mul(z, x);
            x = mul(x, x);
            y /= 2;
        }
        return z;
    }

    int inv(int x)
    {
        return binpow(x, MOD - 2);
    }

    int div(int x, int y)
    {
        return mul(x, inv(y));
    }

    int power(ll x, ll y)
    {
        if (y == 0) return 1;
        int res = power(x, y / 2);
        res = mul(res, res);
        if (y % 2 == 1) res = mul(res, x);
        return res % MOD;
    }
} BN;

void solve()
{
    int n; cin >> n;
    int res = 6;
    ll tmp = (1LL<<n) - 2; // 2^(2n) - 2

    res = BN.mul(res, BN.power(4LL, tmp));
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

