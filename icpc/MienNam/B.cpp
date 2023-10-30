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

#define all(x)         x.begin(),x.end()
#define rr(x)     sort(all(x)),x.resize((unique(all(x))-x.begin()));
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
#define int ll
int a[1005],b[1005],c[1005];
int n,m;
vector<pair<int,ii>> q;

signed main()
{
    setIO("");
    cin>>n>>m;
    ll ans=n*m;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i]>>b[i]>>c[i];
        for(int j=1;j<i;j++)
        {
            int ma=a[i]-a[j],mb=b[i]-b[j],mc=c[i]-c[j];
            int ua=(a[i]==0),ub=(b[i]==0),uc=(c[i]==0);
            int va=(a[j]==0),vb=(b[j]==0),vc=(c[j]==0);
            int ka=ub*vc-vb*uc,kb=-(ua*vc-va*uc),kc=ua*vb-va*ub;
            if (!ka&&!kb&&!kc) continue;
            if (ka*ma+kb*mb+kc*mc==0) {
                int aa=a[i],bb=b[i],cc=c[i];
                if (ua) aa=a[j];
                if (ub) bb=b[j];
                if (uc) cc=c[j];
                q.push_back({aa,{bb,cc}});
            }
        }
    }
    sort(all(q));
    int cnt=1;
    for(int i=1;i<=q.size();i++)
    {
        //cout<<q[i].first<<" "<<q[i].second.first<<" "<<q[i].second.second<<".\n";
        if (i==q.size()||q[i]!=q[i-1])
        {
            if (cnt==1) ans--; else if (cnt==3) ans-=2;
            //cout<<cnt<<endl;
            cnt=1;
        }
        else cnt++;
    }
    cout<<ans;
    return 0;
}

//   _                          _223
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
