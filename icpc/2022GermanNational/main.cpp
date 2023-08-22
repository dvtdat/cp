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

    string t = "shcd";

    string s; cin >> s;
    int n = s.length();

    vector<int> cnt(4, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            if (s[i] == t[k]) cnt[k]++;
        }
    }

    int sum = 0;
    vector<int> d;
    for (int i = 0; i < 4; ++i) if (cnt[i] != 0) d.push_back(i);
    for (int i = 0; i < 4; ++i) sum += cnt[i];

    int res = inf;
    do
    {
        vector<int> visited(30, false);
        int tmp = 0;
        int cost = 0;
        int j = 0;

        for (int i : d)
        {
            j = 0;
            tmp = 0;
            visited[t[i] - 'a'] = true;
            while (j < n && (visited[s[j] - 'a']))
            {
                if (s[j] == t[i]) tmp++;
                j++;
            }
            cost += cnt[i] - tmp;
        }
        res = min(res, cost);
    } while (next_permutation(d.begin(), d.end()));

    cout << res << '\n';
    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
