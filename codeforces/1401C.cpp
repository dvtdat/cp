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
    
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> b = a;
    sort(b.begin(), b.end());

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != a[i]) v.push_back(a[i]);
    }

    if (v.size() == 0)
    {
        cout << "YES\n"; return;
    }
    
    int mn = *min_element(a.begin(), a.end());
    int tmp = mn;

    for (int i = 0; i < v.size(); ++i) tmp = __gcd(tmp, v[i]);

    if (tmp != mn) cout << "NO\n";
    else cout << "YES\n";
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

