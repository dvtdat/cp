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
    int n, k; cin >> n >> k;

    vector<int> a(n);
    vector<ll> p(n + 1);
    vector<ii> b(k);
    vector<ll> res(k);

    for (int &i : a) cin >> i;
    for (int i = 0; i < k; ++i)
    {
        cin >> b[i].first;
        b[i].second = i;
    }

    p[0] = a[0];
    for (int i = 1; i < n; ++i) p[i] = p[i - 1] + a[i];

    sort(b.begin(), b.end());

    int j = 0;
    for (int i = 0; i < k; ++i)
    {
        while (a[j] <= b[i].first && j < n) ++j;
        
        if (j - 1 < 0) res[b[i].second] = 0;
        else res[b[i].second] = p[j - 1];
    }

    for (int i = 0; i < k; ++i) cout << res[i] << ' ';
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

