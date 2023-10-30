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

const int N = 1e5+5;
ll n,k;
ll ans = 0;
ll path[500];
ll cost[30];
vector<vector<ll>> pos;
const int mod = 1e9+7;

ll dfs(ll i,ll step){
    int vt = lower_bound(pos[path[i]].begin(),pos[path[i]].end(),step)-pos[path[i]].begin();
    debug(vt);
    debug(path[i]);
    if (vt == pos[path[i]].size())  return 0;
    if (i == k-1)   return pos[path[i]].size()-vt;
    for (int j=vt;j<pos[path[i]].size();j++){
        ans = ans + (dfs( i+1, pos[path[i]][j] + cost[path[i]] +1))%mod;
    }
}

int main()
{
    setIO("t");
    cin>>k>>n;
    pos.resize(50,vector<ll>());
    for (int i=0;i<26;i++){
        cin>>cost[i];
    }
    string s;
    cin>>s;
    for (int i=0;i<k;i++)   path[i] = s[i]-'A';
    cin>>s;
    for (int i=0;i<n;i++){
        pos[s[i] - 'A'].push_back(i);
    }
    // OUR CODE LIES HERE
    for (int i=0;i<pos[path[0]].size();i++){
        debug(pos[path[0]][i]+cost[path[0]]+1);
        ans = (ans + dfs(1,pos[path[0]][i]+cost[path[0]]+1))%mod;
        debug(ans);
    }
    cout<<ans;
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
