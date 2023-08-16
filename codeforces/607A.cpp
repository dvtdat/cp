// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 1000010;
const ll MOD = 998244353;
const double eps = 1e-12;

bool exist[maxN];
int beam[maxN];
int f[maxN];

void solve()
{
    memset(f, 0, sizeof f);
    memset(exist, false, sizeof exist);
    memset(beam, 0, sizeof beam);
    
    int n; cin >> n;
    
    int u, v;
    for (int i = 0; i < n; ++i)
    {
        cin >> u >> v;
        exist[u] = 1;
        beam[u] = v;
    }

    if (exist[0]) f[0] = 1;

    for (int i = 1; i < maxN; ++i)
    {
        if (exist[i]) f[i] = (i - beam[i] - 1 < 0 ? 0 : f[i - beam[i] - 1]) + 1;
        else f[i] = f[i - 1];
    }

    // for (int i = 0; i < 100; ++i) cout << f[i] << ' ';

    int res = 0;
    for (int i = 1; i < maxN; ++i)
    {   
        res = max(res, f[i]);
    }
    cout << n - res << '\n';
}

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
    setIO("text");
    int test = 1; //cin >> test;
    while (test--) solve();
}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

