//xa hoi nay khong co' cho^~ cho ke? yeu^' :sadge:

#include <bits/stdc++.h>
#define inf INT_MAX
#define N 150

using namespace std;

int a[N][N], f[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    memset(f, inf, sizeof f);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i) f[i][1] = a[i][1];

    for (int j = 2; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            f[i][j] = a[i][j] + max(f[i - 1][j - 1], max(f[i][j - 1], f[i + 1][j - 1]));
        }
    }

    int res = -inf;
    for (int i = 1; i <= n; ++i) res = max(res, f[i][m]);

    cout << res << '\n';
}

