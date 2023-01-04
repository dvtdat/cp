// ny oi em o dau...

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;

void solve()
{
    int n; cin >> n;
    ll sum = 0;
    int mn = inf;
    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        sum += v;
        if (v != 1) mn = min(mn, v);
    }

    if (sum % 2 == 0)
    {
        cout << 0 << '\n'; return;
    }

    int cnt = 0;
    while (mn != 1)
    {
        mn /= 2; cnt++;
    }

    if (n != 1)
    {
        cout << cnt << '\n'; return;
    }
    else
    {
        cout << cnt + 1 << '\n'; return;
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

