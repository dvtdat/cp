#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

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

    ll power(ll x, ll y)
    {
        if (y == 0) return 1;
        ll res = power(x, y / 2);
        res *= res;
        res %= MOD;

        if (y % 2 == 1) res *= x;
        return res % MOD;
    }
};

int main()
{

}