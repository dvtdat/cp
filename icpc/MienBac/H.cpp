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
const int maxN = 210;
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

int main()
{
    setIO("");
    int n, x;
    ll k;

    cin >> n >> x >> k;

    int m = n * (n - 1) / 2;

    if (x > m)
    {
        cout << -1 << '\n'; return 0;
    }

    vector<int> ok;
    for (int i = 1; i <= n; ++i) ok.push_back(i);

    vector<vector<ll>> f(n + 10, vector<ll>(m + 10, 0));
    f[1][0] = 1;

    for (int i = 2; i <= n; ++i)
    {
        int l = 0, r = 0;
        int k = 0;
        int cnt = i * (i - 1) / 2;
        ll total = 0;

        for (int j = 0; j <= cnt; ++j)
        {
            while (l < (j - (i - 1)))
            {
                total -= f[i - 1][l];
                if (total < 0)
                {
                    total += infLL;
                    k--;
                }
                l++;
            }

            while (j >= r)
            {
                total += f[i - 1][r];
                if (total >= infLL)
                {
                    total -= infLL;
                    k++;
                }
                r++;
            }

            if (k > 0) f[i][j] = infLL;
            else f[i][j] = total;
        }
    }

    vector<int> res;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < (int)ok.size(); ++j)
        {
            if (x - j < 0) continue;

            if (k > f[n - i][x - j])
            {
                k -= f[n - i][x - j];
                continue;
            }

            res.push_back(ok[j]);
            x -= j;
            vector<int> tmp;
            for (int c = 0; c < (int)ok.size(); ++c)
            {
                if (c == j) continue;
                tmp.push_back(ok[c]);
            }

            ok = tmp;
            break;
        }
    }

    res.push_back(ok[(int)ok.size() - 1]);
    if (x > 0 || k > 1 || (int)res.size() < n)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < (int)res.size(); ++i) cout << res[i] << ' '; cout << '\n';

    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
