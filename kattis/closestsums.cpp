#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main()
{
    int n, cnt = 1;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i) cin >> a[i];

        int m; cin >> m;

        cout << "Case " << cnt << ':' << endl; cnt++;

        for (int i = 0; i < m; ++i)
        {
            int t; cin >> t;
            int sum = a[0] + a[1];

            for (int j = 0; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    int tmp = a[j] + a[k];
                    if (abs(tmp - t) < abs(sum - t)) sum = tmp;
                }
            }
            cout << "Closest sum to " << t << " is " << sum << "." << endl;
        }
    }
}
