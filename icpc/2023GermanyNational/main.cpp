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

#define sqr(x) (x)*(x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int) (x).size()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define eb emplace_back

ll fgcd(ll a, ll b) { while(b) swap(b, a %= b); return a; }
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c; return ans; }
ll fpow(ll a, ll b) { ll ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans; }
int flog(int x) { return 31 - __builtin_clz(x); }
int flog(ll x) {return 63 - __builtin_clzll(x);}

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

int main()
{
    setIO("");
    // OUR CODE LIES HERE
    vector<string> ans;
    string s,ss;
    cin>>s;
    ss=s;
    for(int i=0;i<s.size();i++) ss[i]=ss[i]-'A'+'a';
    ans.pb(ss);
    for(int i=1;i<s.size();i++)
    {
        if (s[i-1]=='S'&&s[i]=='S')
        {
            string si="";
            for(int j=0;j<i-1;++j) si+=ss[j];
            si+='B';
            for(int j=i;j<ss.size()-1;++j) si+=ss[j+1];
            ans.pb(si);
            ans.pb(ss);
        }
    }
    sort(ans.begin(),ans.end());ans.resize((unique(ans.begin(),ans.end())-ans.begin()));
    for(string i:ans) cout<<i<<endl;
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
