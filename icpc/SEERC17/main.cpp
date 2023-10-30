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

int n;
ll c[5005];
char a[5005],b[5005];
vector<ll> u,v;

int main()
{
    setIO("");
    ll ans=0,tmp=0,tmp1=0,tmp2=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]==49) ans+=c[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        if (b[i]==48&&a[i]==49) u.push_back(c[i]),tmp1+=c[i];
        else if (b[i]==49&&a[i]==48) v.push_back(c[i]),tmp2+=c[i];
    }
    sort(v.begin(),v.end());
    if (v.size()) {
        ll e=v[v.size()-1];
        for(int i=1;i<=n;i++) {
            if (b[i]==49&&a[i]==49) {
                if (c[i]+tmp1+tmp2<c[i]*u.size()+c[i]) {u.push_back(c[i]); v.push_back(c[i]);}
                else tmp+=c[i];
            }
        }
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end(),greater<>());
    ans*=1ll*(int)u.size();
    ll t=1ll*(int)u.size();
    for(ll i:u) {ans-=i*t; t--;}
    t=1ll*(int)v.size();
    ans+=tmp*t;
    for(ll i:v) {ans+=i*t; t--;}
    cout<<ans;
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
