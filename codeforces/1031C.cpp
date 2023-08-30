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
    int n, m; cin >> n >> m;
    vector<int> a, b;

    int total = 0;
    int i;
    for (i = 1; i <= inf; ++i)
    {
        if (total + i > m + n) break;
        total += i;
    }
    i--;
    
    for (int j = i; j >= 1; --j)
    {
        if (n >= j)
        {
            a.push_back(j);
            n -= j;
        }
        else
        {
            b.push_back(j);
            m -= j;
        }
    }

    cout << a.size() << '\n';
    for (int x : a) cout << x << ' '; cout << '\n';

    cout << b.size() << '\n';
    for (int x : b) cout << x << ' '; cout << '\n';
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
    int test = 1; //cin >> test;
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

