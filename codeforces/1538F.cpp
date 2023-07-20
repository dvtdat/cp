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

ll v[20], pre[20];

void process()
{
    v[1] = 1;
    pre[1] = 1;

    for (int i = 2; i <= 15; ++i)
    {
        v[i] = pre[i - 1] * 9 + i;
        pre[i] = pre[i - 1] + v[i];
    }
}

void solve()
{
    int a, b; cin >> a >> b;
    vector<int> _a, _b;

    _a.push_back(0);
    _b.push_back(0);

    while (a != 0)
    {
        _a.push_back(a % 10); a /= 10;
    }

    while (b != 0)
    {
        _b.push_back(b % 10); b /= 10;
    }

    while (_a.size() < _b.size()) _a.push_back(0);

    ll res = 0;
    for (int i = 1; i < _a.size(); ++i)
    {
        int diff = _b[i] - _a[i];
        res += 1LL * diff * v[i];
    }

    cout << res << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    process();
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

