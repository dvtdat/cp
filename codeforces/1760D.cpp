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

    vector<int> a(n + 1);
    vector<int> f1(n, 0), f2(n, 0);

    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b;
    b.push_back(a[0]);
    
    int i = 1;
    while (i < n)
    {
        if (a[i] == b[b.size() - 1])
        {
            i++;
            continue;
        }
        b.push_back(a[i]);
        i++;
    }

    a = b;
    n = b.size();

    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || a[i - 1] > a[i]) f1[i] = 1;
        if (i == n - 1 || a[i] < a[i + 1]) f2[i] = 1; 
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        f1[i] &= f2[i];
        if (f1[i]) cnt++;
    }

    cout << (cnt <= 1 ? "YES" : "NO") << '\n';
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

