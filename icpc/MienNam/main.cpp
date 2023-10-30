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

struct chash { // large odd number for C
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

#define rep(i, a, b) for (int i = a; i < (b); ++i)
const int LIM = 1e6;
bitset<LIM> isPrime;
vi eratosthenes() {
const int S = (int)round(sqrt(LIM)), R = LIM / 2;
vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
vector<ii> cp;
for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
cp.push_back({i, i * i / 2});
for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
}
for (int L = 1; L <= R; L += S) {
array<bool, S> block{};
for (auto &[p, idx] : cp)
for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
rep(i,0,min(S, R - L))
if (!block[i]) pr.push_back((L + i) * 2 + 1);
}
for (int i : pr) isPrime[i] = 1;
return pr;
}

signed main(){
    setIO("");
    vi res = eratosthenes();
}
