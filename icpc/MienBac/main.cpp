#include <bits/stdc++.h>

using namespace std;

template<typename T>
using vt = vector<T>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
using vi = vt<int>;
using vii = vt<ii>;
using vll = vt<ll>;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

ll fgcd(ll a, ll b)
{
    while(b) swap(b, a %= b);
    return a;
}
ll fpow(ll a, ll b, const ll c)
{
    ll ans = 1;
    a %= c;
    for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c;
    return ans;
}
ll fpow(ll a, ll b)
{
    ll ans = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) ans *= a;
    return ans;
}
int flog(int x)
{
    return 31 - __builtin_clz(x);
}
int flog(ll x)
{
    return 63 - __builtin_clzll(x);
}

#define debug(x) { cout << #x << " = "; cout << (x) << endl; }

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    if (!name.size()) return;

#ifndef ONLINE_JUDGE
    freopen((name + ".inp").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
#endif
}

const int MAX = 100001;
vll p;

const int LIM = 1e6;
bitset<LIM> isPrime;
vll sieve()
{
    const int S = (int)round(sqrt(LIM)), R = LIM / 2;
    vll pr = {2}, sieve(S+1);
    pr.reserve(int(LIM/log(LIM)*1.1));
    vector<ii> cp;
    for (int i = 3; i <= S; i += 2) if (!sieve[i])
        {
            cp.emplace_back(i, i * i / 2);
            for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
        }
    for (int L = 1; L <= R; L += S)
    {
        array<bool, S> block{};
        for (auto &[p, idx] : cp)
            for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
        rep(i,0,min(S, R - L))
        if (!block[i]) pr.emb((L + i) * 2 + 1);
    }
    for (int i : pr) isPrime[i] = 1;
    return pr;
}

ll phi(ll n)
{
    ll res = n;

    for (ll i=0; p[i] * p[i] <= n; i++)
    {
        if (n % p[i]== 0)
        {
            res -= (res / p[i]);
            while (n % p[i]== 0)
                n /= p[i];
        }
    }
    if (n > 1)
        res -= (res / n);

    return res;
}

int main()
{
    setIO("");

    p = sieve();

    int a, b;
    cin >> a >> b;

    ll res = 0;
    for (int i = 1; i <= b; ++i)
    {
        (res += phi(i * a)) %= 998244353;
    }
    cout << '\n';
    cout << res << '\n';

    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
