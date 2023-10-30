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

vector<ll> a[20];
string s[20];

int main()
{
    setIO("");
    int t;
    cin>>t;
    while(t--)
    {
        for (int i = 0; i < 20; ++i) {
            a[i].clear();
        }

        int n,l,ans=1e9;
        cin>>l>>n;
        int u=l/50; if (l%50) u++;
        ll v1=(1<<50)-1,v2=(1<<(l%50))-1;
        for(int i=0;i<n;++i)
        {
            cin>>s[i];
            ll e=-1,b=0;
            for(int j=0;j<l;++j)
            {
                e++;
                b+=1ll*(s[i][j]-'0')*(1<<e);
                if (e==49||j==l-1) {a[i].push_back(b); e=-1; b=0;}
            }
        }
        for(int i=0;i<(1<<n);i++)
        {
            int sl=0; vector<ll> s1;
            for(int j=0;j<u;j++) s1.push_back(0ll);
            for(int j=0;j<n;j++)
            {
                if (i&(1<<j))
                {
                    sl++;
                    for(int k=0;k<u;k++) s1[k]|=a[j][k];
                }
            }
            int kt=0;
            for(int k=0;k<u-1;k++)
            {
                if (s1[k]!=v1) {kt++; break;}
            }
            if (l%50&&s1[u-1]!=v2) kt++;
            else if (!(l%50)&&s1[u-1]!=v1) kt++;
            if (!kt) {ans=min(ans,sl);}
        if (ans==1e9) cout<<-1; else cout<<ans;
        cout<<endl;
        }
    }
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
