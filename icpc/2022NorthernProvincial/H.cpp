#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

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
multiset<int> ms;

int main()
{
    setIO("");
    int q;
    cin>>q;
    while (q--){
        string s;
        int x;
        cin>>s;
        if (s=="IN"){
            n++;
            cin>>x;
            ms.insert(x);
//            for (auto itr=ms.begin();itr!=ms.end();itr++)   cout<<*itr<<' ';
//            cout<<'\n';
        }
        if (s=="OUT"){
            n--;
            cin>>x;
            ms.erase(ms.find(x));
//            for (auto itr=ms.begin();itr!=ms.end();itr++)   cout<<*itr<<' ';
//            cout<<'\n';
        }
        if (s=="MEDIAN"){
            if (n&1){
                auto itr=ms.begin();
                for (int nn=n/2;nn!=0;itr++,nn--);
                cout<<*itr<<'\n';
            }
            else{
                auto itr=ms.begin();
                for (int nn=n/2;nn!=0;itr++,nn--);
                cout<<(double)((*(itr)+*(--itr)))/2<<'\n';
            }
            // cout<<'\n';
        }
    }
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|

