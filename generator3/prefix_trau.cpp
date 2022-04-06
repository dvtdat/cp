#include <bits/stdc++.h>
#define N 100100

using namespace std;

int a[N];

int main()
{
    freopen("prefix.inp", "r", stdin);
    freopen("prefix.ans", "w", stdout);

    int n; cin >> n;
    int l, r; cin >> l >> r;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0;

    for (int i = l; i <= r; ++i) res += a[i];

    cout << res;
}

