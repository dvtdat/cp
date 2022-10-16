// little bit of mental headache

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(10);

    int n, l; cin >> n >> l;

    vector<int> a(n);

    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());

    double mx = 0;

    for (int i = 1; i < n; ++i)
    {
        double tmp = (a[i] - a[i - 1]) * 1.0 / 2;
        mx = max(mx, tmp);
    }

    mx = max(a[0] * 1.0, mx);
    mx = max((l - a[n - 1]) * 1.0, mx);

    cout << mx;
}
