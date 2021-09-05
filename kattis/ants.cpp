#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test; cin >> test;
    while (test--)
    {
        int l, n; cin >> l >> n;
        vector<int> a(n);

        for (int&i : a) cin >> i;

        sort(a.begin(), a.end());

        int mx = 0, mn = 0;
        for (int i : a)
        {
            mx = max(mx, max(i, l - i));
            mn = max(mn, min(i, l - i));
        }

        cout << mn << ' ' << mx << endl;
    }
}
