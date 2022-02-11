//toi chi muon duoc hanh. phuc' thoi

#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

int main()
{
    int r, f;
    while (cin >> f && f != 0)
    {
        cin >> r;

        vector<int> _r(r), _f(f);
        vector<double> a(r * f);

        for (int i = 0; i < f; ++i) cin >> _f[i];
        for (int i = 0; i < r; ++i) cin >> _r[i];

        int n = 0;
        for (int i = 0; i < f; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                a[n] = (double)_r[j] / (double)_f[i]; n++;
            }
        }

        sort(a.begin(), a.end());

        double mx = 0;
        for (int i = 0; i < r * f - 1; ++i)
        {
            mx = max(mx, a[i + 1] / a[i]);
        }

        cout << fixed << setprecision(2) << mx << '\n';
    }
}


