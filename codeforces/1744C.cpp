// vl khong the tin dc

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
    char c; cin >> c;

    vector<char> a(n * 3);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n; i < n * 3; ++i) a[i] = a[i - n];

    if (c == 'g')
    {
        cout << 0 << '\n'; return;
    }

    vector<int> b(n * 3);

    int cnt = maxN;
    for (int i = n * 3 - 1; i >= 0; --i)
    {
        if (a[i] != 'g') cnt++;
        else cnt = 0;

        b[i] = cnt;
    }

    int res = 0;
    for (int i = n; i < n * 2; ++i)
    {
        if (a[i] == c) res = max(res, b[i]);
    }

    cout << res << '\n';
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


