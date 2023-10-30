// 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1, 0), p(n + 1, 0);
    ll total = 0, X = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        total ^= a[i];
    }

    string s; cin >> s;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = a[i] ^ p[i - 1];
        if (s[i - 1] == '0') X ^= a[i];
    }
    
    int q; cin >> q;

    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int l, r; cin >> l >> r;
            X ^= p[r] ^ p[l - 1];
        }
        else
        {
            int u; cin >> u;
            cout << (u == 0 ? X : total ^ X) << ' ';
        }
    }
    cout << '\n';
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
    int test; cin >> test;
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

