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
const int maxN = 5000100;
const ll MOD = 998244353;
const double eps = 1e-12;

ll fgcd(ll a, ll b) { while(b) swap(b, a %= b); return a; }
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c; return ans; }
ll fpow(ll a, ll b) { ll ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans; }
int flog(int x) { return 31 - __builtin_clz(x); }
int flog(ll x) {return 63 - __builtin_clzll(x);}

#define debug(x) { cout << #x << " = "; cout << (x) << endl; }

void setIO(string name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    if (!name.size()) return;

    #ifndef ONLINE_JUDGE
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    #endif
}

ll spf[maxN];
ll cnt=0;
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < maxN; i++) spf[i] = i;

    for (int i = 4; i < maxN; i += 2) spf[i] = 2;

    for (int i = 3; i * i < maxN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < maxN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

ll getFactorization(ll x)
{
    ll tmp = x,cur=0;
    while (x != 1)
    {
        if (spf[x]!=cur) {
            cur = spf[x];
            tmp /= cur;
            tmp *= (cur-1);
        }
        x = x / spf[x];
    }
    return tmp;
}

int main()
{
    setIO("");

    sieve();
    ll total = 0;
    ll a, b; cin >> a >> b;

    for (int i = 1; i <= b; ++i)
    {
        (total += getFactorization(a * i)) %= 998244353;
    }
    cout << total;

    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
