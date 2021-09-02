#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> a, int m, int mid)
{
    int cnt = 0;
    for (int i : a)
    {
        if (i != 0) cnt += i / mid + (i % mid == 0 ? 0 : 1);
    }

    return (cnt <= m);
}

int main()
{
    int n, m;
    while (cin >> n >> m && n != -1 && m != -1)
    {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        int l = 0, r = 5000010;
        int ans;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(a, m, mid))
            {
                ans = mid;
                 r = mid - 1;
            }
            else l = mid + 1;
            //cout << l << ' ' << r << endl;
        }
        cout << ans << endl;
    }
}
