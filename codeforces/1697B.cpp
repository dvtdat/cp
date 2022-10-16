#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<long long> p(n + 1);

    p[1] = a[1];

    for (int i = 2; i <= n; ++i) p[i] = p[i - 1] + a[i];

    while (q--)
    {
        int x, y; cin >> x >> y;
        cout << p[n - x + y] - p[n - x] << '\n';
    }
}
