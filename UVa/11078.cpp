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

        cin >> a[0];
        int mn = a[0], mx = a[0], _mx = -inf;

        for (int i = 1; i < n; ++i)
        {
            cin >> a[i];
            _mx = max(_mx, max(mn - a[i], mx - a[i]));
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        cout << _mx << '\n';
    }
}

