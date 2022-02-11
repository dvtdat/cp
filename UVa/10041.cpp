//toi chi muon duoc hanh. phuc' thoi

#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

int main()
{
    int test; cin >> test;
    while (test--)
    {
        int n; cin >> n;

        vector<int> a(n);
        int mn = inf, mx = -inf;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i]; mn = min(mn, a[i]); mx = max(mx, a[i]);
        }

        int _mn = inf;

        for (int i = mn; i < mx; ++i)
        {
            int tmp = 0;
            for (int j = 0; j < n; ++j) tmp += abs(i - a[j]);
            _mn = min(_mn, tmp);
        }

        cout << _mn << '\n';
    }
}




