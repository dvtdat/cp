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

const int N = (int)1e7 + 10;
int a,b,c,d;
int sieve[N];
ll cnt1=0,cnt2=0,res=0;

bool in(int a,int b,int x){
    return (x>=a && x<=b);
}

void solve(int n){
    for (int i=2;i*i<=n;i++){
        if (sieve[i])   continue;
        if (in(a,b,i))  cnt1++;
        if (in(c,d,i))  cnt2++;
        sieve[i] = 1;
        for (int j=2;j*i<=n;j++){
            int x = j * i ;
            if (in(a,b,x))  cnt1++;
            if (in(c,d,x))  cnt2++;
            sieve[x] = 1;
        }
        res+=(cnt1*cnt2);
        cnt1=0;
        cnt2=0;
    }
}

int main()
{
    setIO("");
    cin>>a>>b>>c>>d;
    solve(100);
    debug(res);
    ll ans = (b-a+1) * (d-c+1) - res;
    cout<<ans;
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
