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
    int k; cin >> k;

    vector<int> a(n);
    vector<int> b(n);

    for (int &i : a) cin >> i;

    int q = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] > q && q < k) q = q + 1, b[i] = 1;
        else if (a[i] <= q) b[i] = 1;
        else b[i] = 0; 
    }

    for (int i = 0; i < n; ++i) cout << b[i]; cout << '\n';
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

