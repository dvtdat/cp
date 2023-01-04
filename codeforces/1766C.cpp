// xa hoi

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
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        a[0][i] = (c == 'W' ? 0 : 1);
    }

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        a[1][i] = (c == 'W' ? 0 : 1);
    }

    int flag = 0;
    int i = 0;

    while ((a[0][i] == 1 && a[1][i] == 1) && i < n)
    {
        i++;
    }

    if (i >= n)
    {
        cout << "YES\n"; return;
    }

    flag = (a[0][i] == 1 ? 0 : 1);

    for (i; i < n; ++i)
    {
        if (a[0][i] && a[1][i]) flag = 1 - flag;
        else if (!a[flag][i])
        {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
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

