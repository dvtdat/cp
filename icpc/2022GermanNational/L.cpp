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

char m[110][110];

int main()
{
    setIO("");

    int a, b; cin >> a >> b;
    int k; cin >> k;

    if (a * b % k != 0)
    {
        cout << "impossible\n";
        return 0;
    }

    int cnt = a * b / k;
    char c = 'A';

    int _a = a;
    int _b = b;

    bool flag = false;

    if (k & 1 == a & 1)
    {
        swap(a, b);
        flag = true;
    }

    int tmp = 0;
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (tmp == cnt)
            {
                c = (char)((int)c + 1);
                tmp = 0;
            }
            if (i & 1) m[i][j] = c;
            else m[i][b - j + 1] = c;
            tmp++;
        }
    }


    if (!flag)
    {
        for (int i = 1; i <= a; ++i)
        {
            for (int j = 1; j <= b; ++j) cout << m[i][j]; cout << '\n';
        }
    }
    else
    {
        for (int i = 1; i <= b; ++i)
        {
            for (int j = 1; j <= a; ++j) cout << m[j][i]; cout << '\n';
        }
    }

    return 0;
}

//   _                          _
//  | |__   ___ _ __ ___  _   _| |_
//  | '_ \ / __| '_ ` _ \| | | | __|
//  | | | | (__| | | | | | |_| | |_
//  |_| |_|\___|_| |_| |_|\__,_|\__|
