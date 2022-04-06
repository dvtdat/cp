#include <bits/stdc++.h>
#define N 100100

using namespace std;

int a[N], p[N];

int main()
{
    freopen("prefix.inp", "r", stdin);
    freopen("prefix.out", "w", stdout);

    int n; cin >> n;
    int l, r; cin >> l >> r;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    p[1] = a[1];
    for (int i = 2; i <= n; ++i) p[i] = p[i - 1] + a[i];

    cout << p[r] - p[l - 1];
}
