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

ll n;
unordered_map<ll,ll> mp;
vt<ll> f;

ll calc(ll n,ll id = 0){
    ll ans=0;
    if (n==1)   return 1;
    if (n==8)  return 2;
    if (n==144) return 3;
    if (mp[n]==0){
        int i;
        for (i=id;i<90;i++){
            if (n%f[i]==0){
                ll k = calc(n/f[i],i);
                if (k)  {ans+=calc(n/f[i],i);    break;}
                debug(k);
            }
        }
        if (i<90)        mp[n] = 1;
    }
    return ans;
}

int main(){
    int test;
    cin>>test;
    //solve();
    f.resize(90);
    f[0] = f[1] = 1;
    for (int i=2;i<90;i++)  f[i] = f[i-1] + f[i-2];
    reverse(f.begin(),f.end());
    //for (int i=0;i<13;i++)  cout<<f[i]<<' ';
    //<<'\n';
    while (test--){
        cin>>n;
        cout<<calc(n)<<'\n';
    }
    //debug(dp[13][201]);
}
