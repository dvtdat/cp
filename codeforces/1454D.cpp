// 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
typedef pair<int, ii> iii;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 998244353;
const double eps = 1e-12;

void solve()
{
    ll n; cin >> n;

    vector<ii> v;
    for (ll i = 2; i * i <= n; ++i)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
        if (cnt > 0) v.push_back(ii(cnt, i));
    }
    if (n > 1) v.push_back(ii(1, n));

    sort(v.rbegin(), v.rend());

    int sz = v[0].first;
    vector<ll> res(sz);

    for (int i = 0; i < sz - 1; ++i)
    {
        res[i] = v[0].second;
    }

    res[sz - 1] = v[0].second;
    for (int i = 1; i < v.size(); ++i)
    {
        for (int k = 0; k < v[i].first; ++k) res[sz - 1] *= v[i].second;
    }

    cout << sz << '\n';
    for (ll i : res) cout << i << ' '; cout << '\n';
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

