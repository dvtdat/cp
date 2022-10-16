//0h roi ma anh chua toi'

#include <bits/stdc++.h>
#define maxN 1010

using namespace std;

int a[maxN][maxN], p[maxN][maxN];

int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        p[x1][y1]++;
        p[x1][y2]--;
        p[x2][y1]--;
        p[x2][y2]++;
    }

    int cnt = 0;

    for (int i = 0; i < 1001; ++i)
    {
        for (int j = 0; j < 1001; ++j)
        {
            if (i > 0) p[i][j] += p[i - 1][j];
            if (j > 0) p[i][j] += p[i][j - 1];
            if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];

            if (p[i][j] == k) cnt++;
        }
    }

    cout << cnt;
}
