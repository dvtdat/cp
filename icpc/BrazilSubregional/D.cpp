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

int n,x,y;
unordered_map<ll,int> d;

bool check(ii p){
    return (p.fi > 0 && p.fi < (1<<n) && p.se > 0 && p.se < (1<<n));
}

int bfs(int sx, int sy){
    ll id = sx * (1<<n) + sy;
    d[id] = 0;
    queue<ii> q;
    q.push({sx,sy});
    while (q.size()){
        auto u = q.front(); q.pop();
        int xx = u.fi, yy = u.se;
        if (u == ii(1<<(n-1), 1<<(n-1)) )  return d[xx * (1<<n) + yy];
        ii t1 = {xx*2, yy*2};
        ii t2 = {xx*2, yy*2-(1<<n)};
        ii t3 = {xx*2 - (1<<n), yy*2 - (1<<n)};
        ii t4 = {xx*2 - (1<<n), yy*2};
        if (d[t1.fi * (1<<n) + t1.se] == 0 && check(t1)){
            d[t1.fi * (1<<n) + t1.se] = d[xx * (1<<n) + yy] + 1;
            q.push(t1);
        }
        if (d[t2.fi * (1<<n) + t2.se] == 0 && check(t2)){
            d[t2.fi * (1<<n) + t2.se] = d[xx * (1<<n) + yy] + 1;
            q.push(t2);
        }
        if (d[t3.fi * (1<<n) + t3.se] == 0 && check(t3)){
            d[t3.fi * (1<<n) + t3.se] = d[xx * (1<<n) + yy] + 1;
            q.push(t3);
        }
        if (d[t4.fi * (1<<n) + t4.se] == 0 && check(t4)){
            d[t4.fi * (1<<n) + t4.se] = d[xx * (1<<n) + yy] + 1;
            q.push(t4);
        }
    }
}

signed main(){
    setIO("");
    cin>>n>>x>>y;
    cout<<bfs(x,y);
}

