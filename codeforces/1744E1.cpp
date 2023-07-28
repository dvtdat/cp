// NOT DONE

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

bool isPrime[maxN];
vector<int> prime;

void sieve()
{
    memset(isPrime, true, sizeof isPrime);
    for (int i = 2; i * i <= maxN; ++i)
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= maxN; j += i) isPrime[i] = false;
        prime.push_back(i);
    }
}

vector<int> factor(ll n)
{
    vector<int> factors;
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; ++i)
    {
        while (n % prime[i] == 0)
        {
            factors.push_back(prime[i]);
            n /= prime[i];
        }
    }
    if (n > 1) factors.push_back(n);

    return factors;
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d < c)
    {
        swap(a, b);
        swap(c, d);
    }


}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    sieve();
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

