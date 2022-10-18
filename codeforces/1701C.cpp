// su tuyet vong cua loai nguoi

#include <bits/stdc++.h>

using namespace std;

const int maxN = 200010;

bool check(vector<int> &a, int mid)
{
    long long cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] <= mid) cnt2 += (mid - a[i]) / 2;
        else cnt1 += a[i] - mid;

//        cout << mid << '\n';
//        cout << a[i] << ' ' << cnt1 << ' ' << cnt2 << '\n';
    }

    if (cnt1 <= cnt2) return true;
    return false;
}

void solve()
{
    int n, m; cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < m; ++i)
    {
        int t; cin >> t;
        a[--t]++;
    }
    long long l = 0, r = 2 * (m + n + 10);
    while (l < r)
    {
        long long mid = (l + r) >> 1;
        long long cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] <= mid) cnt2 += (mid - a[i]) / 2;
            else cnt1 += a[i] - mid;
        }

        if (cnt1 <= cnt2) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int test; cin >> test;
    while (test--)
    solve();
}





