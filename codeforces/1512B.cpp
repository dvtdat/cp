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

char c[500][500];

void solve()
{
    memset(c, '.', sizeof c);

    int n; cin >> n;

    int ax, ay, bx, by;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] == '*')
            {
                if (cnt == 0)
                {
                    ax = i; ay = j;
                    cnt++;
                }
                else
                {
                    bx = i, by = j;
                }
            }
        }
    }

    int cx, cy, dx, dy;

    if (ax == bx)
    {
        cy = ay, dy = by;
        if (ax != n - 1) cx = n - 1, dx = n - 1;
        else cx = 0, dx = 0;
    }
    else if (ay == by)
    {
        cx = ax, dx = bx;
        if (ay != n - 1) cy = n - 1, dy = n - 1;
        else cy = 0, dy = 0;
    }
    else
    {
        cx = min(ax, bx);
        dx = max(ax, bx);

        cy = min(ay, by);
        dy = max(ay, by);

        if (cx == ax && cy == ay) swap(cy, dy);
    }

    c[cx][cy] = '*';
    c[dx][dy] = '*';

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << c[i][j];
        }
        cout << '\n';
    }
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

