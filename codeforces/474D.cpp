// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 100010;
const ll MOD = (int)1e9 + 7;
const double eps = 1e-12;

void solve()
{
    int n, k; cin >> n >> k;
    vector<ll> f(maxN + 1, 0);

    for (int i = 0; i < k; ++i) f[i] = 1;

    for (int i = k; i <= maxN; ++i)
    {
        (f[i] = f[i - 1] + f[i - k]) %= MOD;
    }

    f[0] = 0;
    for (int i = 2; i <= maxN; ++i) (f[i] += f[i - 1]) %= MOD;

    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        cout << (f[v] - f[u - 1] + MOD) % MOD << '\n';
    }
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

