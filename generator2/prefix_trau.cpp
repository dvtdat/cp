// kek

#include <bits/stdc++.h>
#define N 100010

using namespace std;

int p[N], a[N];

int main()
{
    freopen("prefix.inp", "r", stdin);
    freopen("prefix.ans", "w", stdout);

    int n, l, r; cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0;
    for (int i = l; i <= r; ++i) res += a[i];

    cout << res;
}

