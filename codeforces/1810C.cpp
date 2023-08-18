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
    int n, c, d; cin >> n >> c >> d;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll total = (n - a.size()) * c;
    ll tmp = infLL;

    for (int i = 0; i < a.size(); ++i)
    {
        tmp = min(tmp, 1LL * (a[i] - i - 1) * d + 1LL * ((int)a.size() - i - 1) * c);
    }
    tmp = min(tmp, 1LL * (int)a.size() * c + d);

    cout << tmp + total << '\n';
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

