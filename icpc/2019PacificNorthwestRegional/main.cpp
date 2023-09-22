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

const int N = (int)1e6 + 10;

bool isPrime[N];
vector<int> primes;

void sieve(int n)
{
    memset(isPrime, true, sizeof isPrime);
    isPrime[1] = false;

    for (int i = 2; i <= n; ++i)
    {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        for (ll j = 1LL * i * i; j <= (ll)n; j += i * 1LL) isPrime[j] = false;
    }

    sort(primes.begin(), primes.end());
}

ii _find(int x)
{
    for (int i = 0; primes[i] <= x / 2; ++i)
    {
        int tmp = x - primes[i];
        if (binary_search(primes.begin(), primes.end(), tmp))
        {
            return ii(primes[i], tmp);
        }
    }
    return ii(-1, -1);
}

int main()
{
    sieve((int)1e6);

    int n; cin >> n;

    ii tmp;
    int cnt = 0;
    int p = 0, q = n;
    while (q - p >= 4)
    {
        tmp = _find(q - p);
        cnt++;
        p = tmp.first;
        q = tmp.second;
    }

    cout << cnt;

    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
