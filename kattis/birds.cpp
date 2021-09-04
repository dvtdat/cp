#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, d, n;
    cin >> l >> d >> n;

    if (n == 0)
    {
        cout << (int)floor((l - 12) / d) + 1 << endl;
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int cnt = 0;

    for (int i = 1; i < n; ++i) cnt += (int)floor((a[i] - a[i - 1]) / d) - 1;

    cnt += (int)floor((a[0] - 6) / d);
    cnt += (int)floor((l - 6 - a[n - 1]) / d);

    cout << cnt;
}
