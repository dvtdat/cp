#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> mn(n + 1, INT_MAX);
        mn[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            mn[i] = min(mn[i + 1], a[i]);
        }

        int cnt = 0;
        vector<bool> mark(n + 1, false);
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > mn[i]) cnt++, mn[n] = min(mn[n], a[i]), mark[i] = true;
        }

        for (int i = 0; i < n; ++i)
        {
            if (!mark[i] && a[i] > mn[n]) cnt++;
        }

        cout << cnt << endl;
    }
}
