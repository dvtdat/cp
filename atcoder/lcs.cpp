// em da xa roi nhung muon trung` moi'

#include <bits/stdc++.h>
#define N 3100

using namespace std;

int f[N][N];

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    for (int i = 0; i <= n; ++i) f[i][0] = 0;
    for (int i = 0; i <= m; ++i) f[0][i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }

    string res = "";

    while (n && m)
    {
        if (a[n - 1] == b[m - 1])
        {
            res = a[n - 1] + res; n--; m--;
        }
        else if (f[n - 1][m] > f[n][m - 1]) n--;
        else m--;
    }

    cout << res;
}
