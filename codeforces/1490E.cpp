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
    vector<ii> a(n + 1, ii(0, 0));

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    
    vector<int> res;
    vector<ll> p(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        if (p[i - 1] >= a[i].first) res.push_back(a[i - 1].second);
        else res.clear();

        p[i] = 1LL * p[i - 1] + 1LL * a[i].first;
    }
    res.push_back(a[n].second);
    
    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';
    cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
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

