#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+10;
int a[N];
int n;

signed main()
{
    freopen("tln.inp", "r", stdin);
    freopen("tln.out", "w", stdout);

    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);

    cout<< max(a[n-1] * a[n-2] * a[n-3], a[n-1] * a[0] * a[1]);
}
