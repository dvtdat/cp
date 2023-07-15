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

ll fib[50];

void process()
{
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= 45; ++i) fib[i] = fib[i - 1] + fib[i - 2];
}

void solve()
{
    ll n, x, y; cin >> n >> x >> y;
    if (n % 2 == 0) swap(x, y);

    for (int i = n; i >= 1; --i)
    {
        if (i == 1 && x == 1 && (y == 1 || y == 2)) break;

        if (i % 2 == 0)
        {
            if (x <= fib[i - 1]) continue;
            else if (fib[i] < x && x <= fib[i + 1])
            {
                x = x - fib[i];
                continue;
            }
        }
        else
        {
            if (y <= fib[i - 1]) continue;
            else if (fib[i] < y && y <= fib[i + 1])
            {
                y = y - fib[i];
                continue;
            }
        }
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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

