// help me pls

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

int a[2][maxN];

void solve()
{
//    for (int i = 1; i < 100000; ++i)
//    {
//        int j = i + 10000007;
//        cout << i << ' ' << j << ' ';
//        cout << __gcd(i, j) << '\n';
//    }


    int a, b; cin >> a >> b;

    if (__gcd(a, b) > 1)
    {
        cout << 0 << '\n'; return;
    }

    b -= a;

    if (b == 1)
    {
        cout << -1 << '\n'; return;
    }

    if (b % 2 == 0)
    {
        cout << 1 << '\n'; return;
    }

    for (int i = 1; i <= b; ++i)
    {
        if (__gcd(i + b, i) > 1)
        {
            cout << i + b - a << '\n'; return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

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


