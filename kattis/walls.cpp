#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int ok[110][110];

int main()
{
    int l, w, n, rad;

    cin >> l >> w >> n >> rad;

    ii mid[4] = {ii(-(l / 2), 0), ii((l / 2), 0),
                 ii(0, -(w / 2)), ii(0, (w / 2))
                };

    for (int i = 0; i < 110; ++i)
        for (int j = 0; j < 110; ++j) ok[i][j] = 0;


    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        for (int l = 0; l < 4; ++l)
        {
            if ((pow(x - mid[l].first, 2) + pow(y - mid[l].second, 2)) <= rad * rad)
            {
                ok[l][i] = 1;
                ok[4][i]++;
                ok[l][n]++;
            }
            mx = max(mx, ok[4][i]);
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (ok[i][n] == 0)
        {
            cout << "Impossible";
            return 0;
        }
    }

    if (mx == 1 || mx == 3 || mx == 4)
    {
        cout << 5 - mx;
        return 0;
    }
    else
    {
        for (int i = 0; i < n - 1; ++i)
        {
            if (ok[4][i] == 2)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    bool flag = true;
                    for (int l = 0; l < 4; ++l)
                    {

                        if (ok[l][i] + ok[l][j] == 0)
                        {
                            flag = false;
                        }
                    }
                    if (flag)
                    {
                        cout << 2;
                        return 0;
                    }
                }
            }
        }
    }

    cout << 3;



}
