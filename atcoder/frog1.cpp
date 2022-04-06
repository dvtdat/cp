//mua xuan tren cao, ngan hoa lap lanh anh nang

#include <bits/stdc++.h>
#define inf 1e10

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n), f(n, inf);

    for (int i = 0; i < n; ++i) cin >> a[i];

    f[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = max(0, i - 2); j < i; ++j)
        {
            f[i] = min(f[i], f[j] + abs(a[i] - a[j]));
        }
    }

    cout << f[n - 1];
}
