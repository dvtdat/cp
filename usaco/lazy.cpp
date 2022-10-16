#include <bits/stdc++.h>
#define maxN 1010

using namespace std;

int p[maxN][maxN];

int main()
{
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> p[i + j][n - i + j - 1   ];
        }
    }

    int t = (n + 1) % 2;
    int res = 0;
    n = n * 2 - 1;

    for (int i = 0; i < n; ++i, t = 1 - t)
    {
        int sum = 0;

        for (int x = max(i - k, 0); x < n && x <= i + k; ++x)
        {
            for (int y = max(t - k, 0); y < n && y <= t + k; ++y)
            {
                sum += p[x][y];
            }
        }

        res = max(res, sum);

        for (int j = t + 1; j + k < n; ++j)
        {
            for (int x = max(i - k, 0); x < n && x <= i + k; ++x)
            {
                if (j - k - 1 >= 0) sum -= p[x][j - k - 1];
                sum += p[x][j + k];
            }

            if (j % 2 == t && res < sum) res = sum;
        }
    }

    cout << res;
}
