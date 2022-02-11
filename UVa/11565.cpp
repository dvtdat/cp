//toi chi muon duoc hanh. phuc' thoi

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test; cin >> test;
    while (test--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        bool flag = false;

        for (int x = -22; x <= 22 && !flag; ++x)
        {
            if (x * x <= c)
            {
                for (int y = -100; y <= 100 && !flag; ++y)
                {
                    if (x * x + y * y <= c && x != y)
                    {
                        for (int z = -100; z <= 100 && !flag; ++z)
                        {
                            if (x != z && y != z
                                && x + y + z == a
                                && x * y * z == b
                                && x * x + y * y + z * z == c)
                            {
                                cout << x << ' ' << y << ' ' << z << '\n';
                                flag = true;
                            }
                        }
                    }
                }
            }
        }

        if (!flag) cout << "No solution.\n";
    }
}

