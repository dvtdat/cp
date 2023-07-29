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
    vector<ll> a(n + 3);
    for (int i = 1; i <= n + 2; ++i)
    {
        cin >> a[i];
    }    

    // x < sum: brute force to find x
    // x => sum: if cant find x, try the other way around

    vector<ll> p(n + 3, 0);
    sort(a.begin(), a.end());

    for (int i = 1; i <= n + 2; ++i)
    {
        p[i] = p[i - 1] + a[i];
    }

    for (int i = 1; i <= n + 1; ++i)
    {
        if (p[n + 1] - a[i] == a[n + 2])
        {
            for (int j = 1; j <= n + 1; ++j)
            {
                if (i == j) continue;
                cout << a[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }

    if (p[n] != a[n + 1])
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << ' ';
    }
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

