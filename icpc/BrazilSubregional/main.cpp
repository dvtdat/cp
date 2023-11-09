#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define all(x)         x.begin(),x.end()
#define rall(x)        x.rbegin(),x.rend()
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
#define rr(x)          sort(all(x)),x.resize((unique(all(x)) - x.begin()));
#define timer cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"

template<typename T> using vt = vector<T>;
using ll = long long;
using ld = long double;
using vi = vt<int>;
using ii = std::pair<int, int>;
using vii = vt<ii>;
using iii = std::pair<int, ii>;

const ll INF = 4e18;
const int inf = INT_MAX;
const int MOD = 1000000003;
const int td[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, tc[8] = {0, 1, 0, -1, -1, 1, 1, -1};

template<class U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U, V>& p) {return out << '(' << p.first << ", " << p.second << ')';}
template<typename T> using minpq = priority_queue<T, vt<T>, greater<T>>;
template<typename T> using maxpq = priority_queue<T>;

ll fgcd(ll a, ll b) {while(b) swap(b, a %= b); return a;}
ll fpow(ll a, ll b, const ll c) { ll ans = 1; a %= c; for(; b; b >>= 1, a = a * a % c) if(b & 1) ans = ans * a % c; return ans;}
ll fpow(ll a, ll b) {ll ans = 1; for(; b; b >>= 1, a *= a) if(b & 1) ans *= a; return ans;}
int flog(int x) {return 31 - __builtin_clz(x);}
int flog(ll x) {return 63 - __builtin_clzll(x);}

void setIO(std::string name) {
    std::cin.tie(0)->sync_with_stdio(0);
    if(sz(name)) {
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int n,k,l;
vi a,b;

void solve(){
    ll s = 0,ans = -1;
    multiset<int>   unsed;
    for (int i=0; i<k; i++) {s+=a[i]; unsed.insert(b[i]);}
    for (int i=0; i<l; i++) {s+=*unsed.rbegin();    unsed.erase(unsed.rbegin());}
    ans = s;
    while (k--){


    }
}

signed main(){
    setIO("");
    cin>>n;
    a.resize(n);    b.resize(n);
    for (auto &x : a)   cin>>x;
    for (auto &x : b)   cin>>x;
    cin>>k>>l;
    solve();
    return 0;
}
