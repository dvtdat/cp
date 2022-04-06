// meo ngu qua' hjx

#include <bits/stdc++.h>
#define inf INT_MAX
#define N 100100

using namespace std;

int a[N], p[N], m[N];

int main()
{
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    p[0] = 0; p[1] = a[1];
    for (int i = 2; i <= n; ++i) p[i] = p[i - 1] + a[i];

    m[n] = a[n];
    for (int i = n - 1; i > 0; --i) m[i] = min(m[i + 1], a[i]);

    double mx = 0;
    vector<int> res;

    for (int i = 2; i < n; ++i)
    {
        double tmp = (p[n] - p[i - 1] - m[i + 1]) * 1.0 / (n - i);
        mx = max(tmp, mx);
        //cout << setprecision(3) << fixed << tmp << endl;
    }

    for (int i = 2; i < n; ++i)
    {
        double tmp = (p[n] - p[i - 1] - m[i + 1]) * 1.0 / (n - i);
        if (tmp == mx) res.push_back(i - 1);
    }

    for (int i : res) cout << i << endl;
}
